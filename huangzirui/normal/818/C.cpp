#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=100010;
struct sofa{
	int x1,y1,x2,y2,id;
	int w[5];
}s[maxn];
bool cmp1(sofa a,sofa b){
	return a.x1<b.x1;
}
int i,j,k,n,m,T,X1[maxn],Y1[maxn],X2[maxn],Y2[maxn];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>k;
	cin>>n>>m;
	for(i=1;i<=k;i++){
		int a=read(),b=read(),c=read(),d=read();
		if(a>c)swap(a,c);
		if(b>d)swap(b,d);
		s[i]={a,b,c,d};
		X1[i]=s[i].x1;
		Y1[i]=s[i].y1;
		X2[i]=s[i].x2;
		Y2[i]=s[i].y2;
	}
	sort(X1+1,X1+1+k);
	sort(Y1+1,Y1+1+k);
	for(i=1;i<=k;i++){
		s[i].w[0]=lower_bound(X1+1,X1+1+k,s[i].x2)-X1-1;
		if(s[i].x1<s[i].x2)s[i].w[0]--;
	}
	for(i=1;i<=k;i++){
		s[i].w[3]=lower_bound(Y1+1,Y1+1+k,s[i].y2)-Y1-1;
		if(s[i].y1<s[i].y2)s[i].w[3]--;
	}
	sort(X2+1,X2+1+k);
	sort(Y2+1,Y2+1+k);
	for(i=1;i<=k;i++){
		s[i].w[1]=k-(upper_bound(X2+1,X2+1+k,s[i].x1)-X2-1);
		if(s[i].x1<s[i].x2)s[i].w[1]--;
	}
	for(i=1;i<=k;i++){
		s[i].w[2]=k-(upper_bound(Y2+1,Y2+1+k,s[i].y1)-Y2-1);
		if(s[i].y1<s[i].y2)s[i].w[2]--;
	}
	bool B=1;
	int a=read(),b=read(),c=read(),d=read();
	for(i=1;i<=k;i++){
		if(a==s[i].w[0] && b==s[i].w[1] && c==s[i].w[3] && d==s[i].w[2]){
			B=0;
			cout<<i<<' ';
		}
	//	cout<<"i="<<i<<' '<<s[i].w[0]<<' '<<s[i].w[1]<<' '<<s[i].w[2]<<' '<<s[i].w[3]<<endl;
	}
	if(B)puts("-1");
}