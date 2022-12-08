#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define INF INT_MAX/2
#define int long long
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define C 1000000000
#define val 1000000

int maxi(int a,int b,int c){
	return max(max(a,b),c);
}

int mini(int a,int b,int c){
	return min(min(a,b),c);
}


int ax,ay,bx,by,cx,cy;

void solve(){
	if(ay!=by || by!=cy){
		if(ay>by && ay>cy){
			cout<<ax<<" "<<ay<<endl;
			ay--;
		}
		else if(ay<by && ay<cy){
			cout<<ax<<" "<<ay<<endl;
			ay++;
		}
		else if(by>cy && by>ay){
			cout<<bx<<" "<<by<<endl;
			by--;
		}
		else if(by<cy && by<ay){
			cout<<bx<<" "<<by<<endl;
			by++;
		}
		else if(cy>by && cy>ay){
			cout<<cx<<" "<<cy<<endl;
			cy--;
		}
		else if(cy<by && cy<ay){
			cout<<cx<<" "<<cy<<endl;
			cy++;
		}
	}
	else if(ax!=bx || bx!=cx){
		if(ax>bx && ax>cx){
			cout<<ax<<" "<<ay<<endl;
			ax--;
		}
		else if(ax<bx && ax<cx){
			cout<<ax<<" "<<ay<<endl;
			ax++;
		}
		else if(bx>cx && bx>ax){
			cout<<bx<<" "<<by<<endl;
			bx--;
		}
		else if(bx<cx && bx<ax){
			cout<<bx<<" "<<by<<endl;
			bx++;
		}
		else if(cx>bx && cx>ax){
			cout<<cx<<" "<<cy<<endl;
			cx--;
		}
		else if(cx<bx && cx<ax){
			cout<<cx<<" "<<cy<<endl;
			cx++;
		}
	}
	else{
		cout<<ax<<" "<<ay<<endl;
		return;
	}
	solve();
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>ax>>ay>>bx>>by>>cx>>cy;

	cout<<maxi(ax,bx,cx)-mini(ax,bx,cx)+1+maxi(ay,by,cy)-mini(ay,by,cy)<<endl;
	
	
	solve();

}