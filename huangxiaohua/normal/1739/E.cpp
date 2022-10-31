#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,f[200500][2][2][2],tot,cur,res=1e9;
string s[2];
void chkmn(int &x,int y){
	x=min(x,y);
}

int main(){
	memset(f,1,sizeof(f));
	
	ios::sync_with_stdio(0);
	cin>>n>>s[0]>>s[1];
	s[0]="0"+s[0]+"0";
	s[1]="0"+s[1]+"0";
	for(auto &i:s[0]){i-='0';tot+=i;}
	for(auto &i:s[1]){i-='0';tot+=i;}
	
	f[1][0][s[1][1]][s[0][2]]=0;
	for(i=1;i<=n;i++){
		int i1,i2,i3;
		for(i1=0;i1<=1;i1++)for(i2=0;i2<=1;i2++)for(i3=0;i3<=1;i3++){
			cur=f[i][i1][i2][i3];
			if(i==n){
				res=min(res,cur);continue;
			}
			if(i2&&i3){
				chkmn(f[i+1][i1][ s[i1^1][i+1] ][ s[i1][i+2] ],cur+1);
				chkmn(f[i+1][i1^1][ 0 ][ s[i1^1][i+2] ],cur+1);
			}
			else if(i2){
				chkmn(f[i+1][i1^1][ s[i1][i+1] ][ s[i1^1][i+2] ],cur);
				chkmn(f[i+1][i1][ s[i1^1][i+1] ][ s[i1][i+2] ],cur+1);
			}
			else{
				chkmn(f[i+1][i1][ s[i1^1][i+1] ][ s[i1][i+2] ],cur);
			}
		}
	}
	
	cout<<tot-res;
}