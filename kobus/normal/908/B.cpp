#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int vx[4]={0,1,0,-1};
int vy[4]={-1,0,1,0};

char ma[112][112];

int x,y;
int l,c;

bool valid(){
	if(x<0||y<0||y==l||x==c)return 0;
	if(ma[y][x]=='#')return 0;
	return 1;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>l>>c;

	int xcom=0,ycom=0;

	for(int i=0;i<l;i++){
		for(int j=0;j<c;j++){
			cin>>ma[i][j];
			if(ma[i][j]=='S'){
				xcom=j;
				ycom=i;
			}
		}
	}

	string s;
	cin>>s;
	int resp=0;

	for(int d0=0;d0<4;d0++){
		for(int d1=0;d1<4;d1++){
			for(int d2=0;d2<4;d2++){
				for(int d3=0;d3<4;d3++){
					if(d0==d1||d1==d2||d2==d3||d0==d3||d0==d2||d1==d3)continue;
					x=xcom;y=ycom;
					bool deu=true;
					//cout<<"teste "<<d0<<" "<<d1<<" "<<d2<<" "<<d3<<endl;
					for(int i=0;i<s.size();i++){
						if(s[i]=='0'){
							x+=vx[d0];
							y+=vy[d0];
						}
						if(s[i]=='1'){
							x+=vx[d1];
							y+=vy[d1];
						}
						if(s[i]=='2'){
							x+=vx[d2];
							y+=vy[d2];
						}
						if(s[i]=='3'){
							x+=vx[d3];
							y+=vy[d3];
						}
						if(!valid()){
							deu=false;
							break;
						}
						if(ma[y][x]=='E'){
							break;
						}
						//cout<<x<<" "<<y<<endl;
					}
					if(deu && ma[y][x]=='E')
						resp++;
					//else cout<<"naochegou"<<endl;
					//cout<<endl<<endl;
				}
			}
		}
	}

	cout<<resp<<endl;

	return 0;
}