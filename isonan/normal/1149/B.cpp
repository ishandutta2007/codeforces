#include <cstdio>
#include <set>

using std::min;

std::set<int>exi[26];
char str[200001];
int pos[200001][3],P[200001],cnt[3],n,q,tot,ans[3],f[251][251][251];
char get(){
	char ch=getchar();
	while(ch!='+'&&ch!='-'&&(ch<'a'||ch>'z'))ch=getchar();
	return ch;
}
void rebuild(){
}
int getmin(int x,char a){
	if(x==n+1)return n+1;
	return *exi[a-'a'].upper_bound(x);
} 
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		exi[str[i]-'a'].insert(i);
	}
	for(int i=0;i<26;i++)exi[i].insert(n+1);
	for(int i=1,l;i<=q;i++){
		char opt=get();
		scanf("%d",&l);
		--l;
		if(opt=='+'){
			char a=get();
			pos[++cnt[l]][l]=a;
			if(l==0){
				for(int i=0;i<=cnt[1];i++)
					for(int j=0;j<=cnt[2];j++)
						f[cnt[0]][i][j]=min(min(cnt[0]?getmin(f[cnt[0]-1][i][j],pos[cnt[0]][0]):n+1,i?getmin(f[cnt[0]][i-1][j],pos[i][1]):n+1),j?getmin(f[cnt[0]][i][j-1],pos[j][2]):n+1);
			}
			else if(l==1){
				for(int i=0;i<=cnt[0];i++)
					for(int j=0;j<=cnt[2];j++)
						f[i][cnt[1]][j]=min(min(cnt[1]?getmin(f[i][cnt[1]-1][j],pos[cnt[1]][1]):n+1,i?getmin(f[i-1][cnt[1]][j],pos[i][0]):n+1),j?getmin(f[i][cnt[1]][j-1],pos[j][2]):n+1);
			}
			else{
				for(int i=0;i<=cnt[0];i++)
					for(int j=0;j<=cnt[1];j++)
						f[i][j][cnt[2]]=min(min(cnt[2]?getmin(f[i][j][cnt[2]-1],pos[cnt[2]][2]):n+1,i?getmin(f[i-1][j][cnt[2]],pos[i][0]):n+1),j?getmin(f[i][j-1][cnt[2]],pos[j][1]):n+1);
			}
		}
		else{
			--cnt[l];
		}
		if(f[cnt[0]][cnt[1]][cnt[2]]!=n+1)puts("YES");
		else puts("NO");
	}
}