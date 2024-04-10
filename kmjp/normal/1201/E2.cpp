#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int D[2][1010][1010];
pair<int,int> from[2][1010][1010];
int H,W;
int X1,X2,Y1,Y2;
int TX,TY1,TY2;
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	
	FOR(y,H+1) FOR(x,W+1) D[0][y][x]=D[1][y][x]=1<<30;
	
	queue<int> Q;
	TY1=H/2;
	TY2=H/2+1;
	TX=W/2;
	D[0][TY1][TX]=0;
	D[1][TY2][TX]=0;
	Q.push(0*4000000+(TY1)*2000+TX);
	Q.push(1*4000000+(TY2)*2000+TX);
	while(Q.size()) {
		int id=Q.front()/4000000;
		int cy=Q.front()/2000%2000;
		int cx=Q.front()%2000;
		Q.pop();
		
		FOR(i,8) {
			int tx=cx+dx[i];
			int ty=cy+dy[i];
			if(tx<1 || tx>W || ty<1 || ty>H) continue;
			
			if(D[id][ty][tx]>D[id][cy][cx]+1) {
				D[id][ty][tx]=D[id][cy][cx]+1;
				Q.push(id*4000000+ty*2000+tx);
				from[id][ty][tx]={cy,cx};
			}
		}
	}
	
	cin>>Y1>>X1>>Y2>>X2;
	
	
	if(D[0][Y1][X1]+1<=D[0][Y2][X2] && D[0][Y1][X1]<=D[1][Y2][X2]) {
		cout<<"WHITE"<<endl;
		while(X1!=TX || Y1 !=TY1) {
			auto a=from[0][Y1][X1];
			X1=a.second;
			Y1=a.first;
			cout<<Y1<<" "<<X1<<endl;
			if(X1==TX&&Y1==TY1) return;
			cin>>y>>x;
		}
		return;
	}
	if(D[1][Y2][X2]+2<=D[1][Y1][X1] && D[1][Y2][X2]+1<=D[0][Y1][X1]) {
		cout<<"BLACK"<<endl;
		cin>>y>>x;
		while(X2!=TX || Y2 !=TY2) {
			auto a=from[1][Y2][X2];
			X2=a.second;
			Y2=a.first;
			cout<<Y2<<" "<<X2<<endl;
			if(X2==TX&&Y2==TY2) return;
			cin>>y>>x;
		}
		return;
	}
	if((X1+Y1)%2==(X2+Y2)%2) {
		cout<<"BLACK"<<endl;
		cin>>Y1>>X1;
		if(D[1][Y2][X2]>D[0][Y1][X1]) {
			while(Y2!=TY1 || X2!=TX) {
				if(abs(Y1-Y2)+abs(X1-X2)==3 && abs(Y1-Y2)>=1&&abs(Y1-Y2)<=2) {
					cout<<Y1<<" "<<X1<<endl;
					return;
				}
				auto a=from[0][Y2][X2];
				X2=a.second;
				Y2=a.first;
				cout<<Y2<<" "<<X2<<endl;
				cin>>Y1>>X1;
			}
		}
		if(abs(Y1-Y2)+abs(X1-X2)==3 && abs(Y1-Y2)>=1&&abs(Y1-Y2)<=2) {
			cout<<Y1<<" "<<X1<<endl;
			return;
		}
		while(1) {
			auto a=from[1][Y2][X2];
			X2=a.second;
			Y2=a.first;
			cout<<Y2<<" "<<X2<<endl;
			if(Y2==TY2&&X2==TX) return;
			cin>>Y1>>X1;
		}
	}
	else {
		cout<<"WHITE"<<endl;
		if(D[0][Y1][X1]>D[1][Y2][X2]) {
			while(Y1!=TY2 || X1!=TX) {
				if(abs(Y1-Y2)+abs(X1-X2)==3 && abs(Y1-Y2)>=1&&abs(Y1-Y2)<=2) {
					cout<<Y2<<" "<<X2<<endl;
					return;
				}
				auto a=from[1][Y1][X1];
				X1=a.second;
				Y1=a.first;
				cout<<Y1<<" "<<X1<<endl;
				cin>>Y2>>X2;
			}
		}
		if(abs(Y1-Y2)+abs(X1-X2)==3 && abs(Y1-Y2)>=1&&abs(Y1-Y2)<=2) {
			cout<<Y2<<" "<<X2<<endl;
			return;
		}
		while(1) {
			auto a=from[0][Y1][X1];
			X1=a.second;
			Y1=a.first;
			cout<<Y1<<" "<<X1<<endl;
			if(Y1==TY1&&X1==TX) return;
			cin>>Y2>>X2;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}