#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int kase;
int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
struct node{
	bool f[11][11];
	node(){memset(f,0,sizeof f);For(i,1,8)For(j,1,8)f[i][j]=1;}
	node change(int k){
		k+=4;k%=8; 
		node x;
		rep(i,8)rep(j,8)
			x.f[i][j]=f[i+dir[k][0]][j+dir[k][1]];
		return x;
	}
	inline void output(){
		rep(i,8){rep(j,8)cout<<f[i][j];puts("");}
	}
};
string s;
inline int check(string s){
	if(s=="Up")return 0;
	if(s=="Up-Right")return 1;
	if(s=="Right")return 2;
	if(s=="Down-Right")return 3;
	if(s=="Down")return 4;
	if(s=="Down-Left")return 5;
	if(s=="Left")return 6;
	if(s=="Up-Left")return 7;
	return -114514;
}
void clear(node &x,int i,int j){
	rep(l,8)x.f[i][l]=x.f[l][j]=0;
	rep(a,8)rep(b,8)if(abs(a-i)==abs(b-j))x.f[a][b]=0;
	
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	rep(fuck,kase=read()){
		node now;cout<<"1 1"<<endl;fflush(stdout);
		int i=1,j=1;
		cin>>s;if(s=="Done")continue;
		now=now.change(check(s));
		while(1){
//			now.output();
			clear(now,i,j);
			int f=0;
			For(l,1,8)if(now.f[i+1][l]){
				cout<<i<<" "<<l<<endl;j=l;fflush(stdout);
				f=1;break;
			}
			if(!f){cout<<++i<<" "<<j<<endl;fflush(stdout);}
			cin>>s;
			if(s=="Done")break;
			now=now.change(check(s));
			
		}
	}
	return 0;
}