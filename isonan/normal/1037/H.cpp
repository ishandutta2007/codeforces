#include <cstdio>
#include <cstring>
#include <algorithm>

char s[200001];
int a[200001],rank[200001],tp[200001],tax[200001],sa[200001],m,n,q;
void Qsort(){
	for(int i=0;i<=m;i++)tax[i]=0;
	for(int i=1;i<=n;i++)++tax[rank[i]];
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n;i;i--)sa[tax[rank[tp[i]]]--]=tp[i];
}
void Ssort(){
	for(int i=1;i<=n;i++)rank[i]=a[i]=s[i]-'a'+1,tp[i]=i;
	m=1000;
	Qsort();
	for(int w=1,p=1;p<n;m=p,w<<=1){
		p=0;
		for(int i=1;i<=w;i++)tp[++p]=n-w+i;
		for(int i=1;i<=n;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		Qsort();
		std::swap(rank,tp);
		rank[sa[1]]=p=1;
		for(int i=2;i<=n;i++)
			rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
}
int find(int l,int r,int len,int x){
	//> 
	int mid,ans=r+1;
	while(l<=r){
		mid=(l+r)>>1;
		if(sa[mid]+len<=n&&a[sa[mid]+len]>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int cnt[26][100001];
int root[100001],lson[6000001],rson[6000001],se[6000001],Cnt;
void add(int &pos,int pre,int l,int r,int e){
	pos=++Cnt;
	se[pos]=se[pre]+1;
	lson[pos]=lson[pre];
	rson[pos]=rson[pre];
	if(l==r)return;
	if((l+r)>>1>=e)add(lson[pos],lson[pre],l,(l+r)>>1,e);
	else add(rson[pos],rson[pre],((l+r)>>1)+1,r,e);
}
bool query(int pos,int pre,int l,int r,int el,int er){
	if(el>r||er<l)return 0;
	if(el<=l&&er>=r)return se[pos]>se[pre];
	return query(lson[pos],lson[pre],l,(l+r)>>1,el,er)|query(rson[pos],rson[pre],((l+r)>>1)+1,r,el,er);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	Ssort();
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)cnt[j][i]=cnt[j][i-1];
		++cnt[s[i]-'a'][i];
	}
	for(int i=1;i<=n;i++)add(root[i],root[i-1],1,n,sa[i]);
	scanf("%d",&q);
//	for(int i=1;i<=n;i++)printf("%d ",sa[i]);putchar('\n');
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d%s",&l,&r,s+1);
		int nl=strlen(s+1);
		int L=1,R=n;
		int ansL,ansR,anslen=-1;
		for(int j=1;j<=nl+1&&L<=R;j++){
			int t1=find(L,R,j-1,s[j]-'a'+1),t2=find(L,R,j-1,s[j]-'a'+2);
//			printf("%d %d\n",t1,t2);
			if(query(root[R],root[t2-1],1,n,l,r-j+1)){
				ansL=t2;
				ansR=R;
				anslen=j;
			}
			L=t1;
			R=t2-1;
		}
//		printf("%d %d %d\n",ansL,ansR,anslen);
		if(!~anslen){
			bool out=0;
			for(int j=0;j<26;j++)
				if(j>s[1]-'a'&&cnt[j][r]>cnt[j][l-1]){
					putchar('a'+j);putchar('\n');
					out=1;
					break;
				}
			if(!out)puts("-1");
		}
		else{
			int L=ansL,ans,mid;
			while(ansL<=ansR){
				mid=(ansL+ansR)>>1;
				if(query(root[mid],root[L-1],1,n,l,r-anslen+1))ans=mid,ansR=mid-1;
				else ansL=mid+1;
			}
//			printf("%d\n",ans);
			for(int j=1;j<=anslen;j++)putchar(a[j+sa[ans]-1]+'a'-1);putchar('\n');
		}
	}
}