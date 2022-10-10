#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,F[11]={0,1,5,-1,-1,2,-1,-1,8,-1};
string S;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>S;
		int a=(S[0]-'0')*10+(S[1]-'0');
		int b=(S[3]-'0')*10+(S[4]-'0');
		while(1){
			int x0=a/10,x1=a%10,y0=b/10,y1=b%10;
			if(F[x0]<0 || F[x1]<0 || F[y0]<0 || F[y1]<0);
			else{
				int X0=F[x0],X1=F[x1],Y0=F[y0],Y1=F[y1];
				swap(X0,Y1);
				swap(X1,Y0);
				X0=X0*10+X1;
				Y0=Y0*10+Y1;
				if(X0<n && Y0<m){
					cout<<x0<<x1<<":"<<y0<<y1<<endl;
					break;
				}
			}
			b++;
			if(b==m)a++,b=0;
			if(a==n)a=0;
		}
	}
	return 0;
}