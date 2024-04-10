#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,r,ans,a[210000],s[210000],L[210000],R[210000];
int cnt,c[210000],tot,num[210000],top; pii t[210000];
vector<int> vec[210000];
void mypush(int x){
	if (top&&t[top].first<=x&&x<=t[top].second) return;
	if (top&&x<t[top].first){
		t[top].first--;
		if (top>1&&t[top].first<=t[top-1].second) t[top-1].second=t[top].second,top--;
	} else
		if (!top||x>t[top].second) t[++top]=pii(x,x);
}
void work(int x){
	int lst=0; cnt=0;
	for (int now:vec[x]){
		c[++cnt]=s[now]-s[lst];
		lst=now;
	}
	c[++cnt]=s[n]-s[lst];
	int sum=0;
	top=1; t[1]=pii(0,0);
	for (int i=1;i<=cnt;i++){
		sum+=c[i]; mypush(sum);
		if (i!=cnt){ sum--; mypush(sum);}
	}
	tot=0;
	for (int i=1;i<=top;i++)
		for (int j=t[i].first;j<=t[i].second;j++)
			num[++tot]=j;
	for (int i=1;i<=tot;i++) L[i]=INF,R[i]=-INF;
	sum=0;
	int j=1,k=0;
	while (num[j]<0) j++;
	L[j]=0; lst=0;
	for (int i=1;i<=cnt;i++){
		while (j<=tot&&num[j]-sum<=c[i]){
			int pos=k+(num[j]-sum);//num[j]-sum r
			L[j]=min(L[j],max(lst,pos?vec[r][pos-1]:0));
			R[j]=max(R[j],max(lst,pos==vec[r].size()?n:vec[r][pos]-1));
			j++;
		}
		sum+=c[i]; k+=c[i];
		if (i!=cnt){
			sum--;
			if (j&&num[j-1]-sum>0) j--;
			if (j&&num[j-1]-sum==0){
				L[j-1]=min(L[j-1],vec[x][i-1]);
				R[j-1]=max(R[j-1],(k==vec[r].size()?n:vec[r][k]-1));
			}
		} else{
			if (j&&num[j-1]-sum==0){
				L[j-1]=min(L[j-1],n);
				R[j-1]=max(R[j-1],n);
			}
		}
	}
	for (int i=1;i<=tot;i++) ans=max(ans,R[i]-L[i]);
}
int main(){
//	mt19937 random(233);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
//		a[i]=random()%10+1;
		scanf("%d",&a[i]);
		vec[a[i]].push_back(i);
	}
	r=1;
	for (int i=2;i<=n;i++)
		if (vec[i].size()>vec[r].size()) r=i;
	for (int i=1;i<=n;i++)
		if (i!=r&&vec[i].size()==vec[r].size()){
			printf("%d\n",n);
			return 0;
		}
	for (int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]==r);

	ans=0;
	for (int i=1;i<=n;i++){
		if (r==i) continue;
		work(i);
	}
	printf("%d\n",ans);
	return 0;
}