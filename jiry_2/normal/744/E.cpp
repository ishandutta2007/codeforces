#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo1=1e9+9,mo2=998244353;
const int key1=10007,key2=10009;
int Key1[110000],Key2[110000],w1[110000],w2[110000];
int n,L[40],R[40],len;
char ch[110000];
int go[210000][32],where[210000],bo[210000],sign;
int in[210000],pd[210000],low[210000],dfs[210000],flag;
int l,r,head,s[210000],flag2;
void solve(int k){
//	cout<<"asd "<<k<<endl;
	s[++head]=k; pd[k]=flag; dfs[k]=low[k]=++sign; in[k]=1;
	for (int i=l;i<=r&&flag2==0;i++)
		if (go[k][i]){
			int j=go[k][i];
			if (pd[j]!=flag){
				solve(j); low[k]=min(low[k],low[j]);
			} else if (in[j]) low[k]=min(low[k],dfs[j]);
		}
	if (dfs[k]==low[k]){
		int size=0,fl=0;
	//	if (l==1&&r==4) cout<<"group"<<endl;
		while (1){
			fl|=bo[s[head]];
			in[s[head]]=0;
		//	if (l==1&&r==4) cout<<s[head]<<" ";
			size++; head--;
			if (s[head+1]==k) break;
		}
		if (size>1&&fl) flag2=1;
	//	if (l==1&&r==4) cout<<endl;
	}
}
int check(int a,int b){
//	cout<<"asd "<<a<<" "<<b<<endl;
	l=a; r=b; flag++; sign=0; head=0; flag2=0;
	for (int i=L[a];i<=R[b];i++){
		if (pd[i]!=flag){
			solve(i); if (flag2) return 0;
		}
		if (pd[i+len]!=flag){
			solve(i+len); if (flag2) return 0;
		}
	}
	if (pd[len*2+1]!=flag){
		solve(len*2+1); if (flag2) return 0;
	}
	return 1;
}
int get1(int l,int r){
	return ((w1[r]-1ll*w1[l-1]*Key1[r-l+1])%mo1+mo1)%mo1;
}
int get2(int l,int r){
	return ((w2[r]-1ll*w2[l-1]*Key2[r-l+1])%mo2+mo2)%mo2;
}
int eq(int l1,int r1,int l2,int r2){
	return get1(l1,r1)==get1(l2,r2)&&get2(l1,r1)==get2(l2,r2);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		L[i]=len+1;
		scanf("%s",ch+len+1);
		len+=strlen(ch+len+1);
		R[i]=len;
	}
	Key1[0]=1; Key2[0]=1;
	for (int i=1;i<=len;i++){
		Key1[i]=1ll*Key1[i-1]*key1%mo1;
		Key2[i]=1ll*Key2[i-1]*key2%mo2;
	}
	for (int i=1;i<=n;i++)
		for (int j=L[i];j<=R[i];j++) where[j]=i,where[j+len]=i,bo[j]=bo[+len]=(j!=L[i]);
	for (int i=1;i<=len;i++){
		w1[i]=(1ll*w1[i-1]*key1+ch[i])%mo1;
		w2[i]=(1ll*w2[i-1]*key2+ch[i])%mo2;
	}
	for (int now=1;now<=n;now++)
		for (int i=L[now];i<=R[now];i++)
			for (int j=1;j<=n;j++){
				int ll=min(R[now]-i+1,R[j]-L[j]+1);
				int l1=i,r1=i+ll-1;
				int l2=L[j],r2=l2+ll-1;
			/*	if (i==1&&j==2){
					cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
					cout<<get1(l1,r1)<<" "<<get2(l2,r2)<<endl;
				}*/
				if (eq(l1,r1,l2,r2)==0) continue;
				if (R[now]-i+1<R[j]-L[j]+1){
					go[i][j]=len+L[j]+ll;
					go[i+len][j]=L[j]+ll;
				} else if (R[now]-i+1>R[j]-L[j]+1){
					go[i][j]=i+ll;
					go[i+len][j]=i+len+ll;
				} else {
					go[i][j]=len*2+1;
					go[i+len][j]=len*2+1;
				}
			}
	for (int i=1;i<=n;i++) go[len*2+1][i]=L[i];
	/*for (int i=1;i<=len*2+1;i++){
		cout<<"go "<<i<<" "<<bo[i]<<endl;
		for (int j=1;j<=n;j++)
			cout<<go[i][j]<<" "; cout<<endl;}*/
	int now=1,ans=0;
	for (int i=1;i<=n;i++){
		now=max(now,i);
		while (now<=n&&check(i,now)) now++;
		ans+=now-i;
	}
	cout<<ans<<endl;
	return 0;
}