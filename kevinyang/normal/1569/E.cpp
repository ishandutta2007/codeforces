#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
vector<int>powers(105);
bool check(int k, vector<int>a){
	bool f = true;
	if(k==3){
		for(int i = 0; i<(1<<(k-1)); i+=2){
			int cnt = 0;
			for(int j = 0; j<2; j++){
				cnt+=(a[i+j]==5);
			}
			if(cnt!=1)return false;
		}
	}
	if(k==4){
		for(int i = 0; i<(1<<(k-1)); i+=2){
			int cnt = 0;
			for(int j = 0; j<2; j++){
				cnt+=(a[i+j]==9);
			}
			if(cnt!=1)return false;
		}
		for(int i = 0; i<(1<<(k-1)); i+=4){
			int cnt = 0;
			for(int j = 0; j<4; j++){
				cnt+=(a[i+j]==5);
			}
			if(cnt!=1)return false;
		}
	}
	if(k==5){
		for(int i = 0; i<(1<<(k-1)); i+=2){
			int cnt = 0;
			for(int j = 0; j<2; j++){
				cnt+=(a[i+j]==17);
			}
			if(cnt!=1)return false;
		}
		for(int i = 0; i<(1<<(k-1)); i+=4){
			int cnt = 0;
			for(int j = 0; j<4; j++){
				cnt+=(a[i+j]==9);
			}
			if(cnt!=1)return false;
		}
		for(int i = 0; i<(1<<(k-1)); i+=8){
			int cnt = 0;
			for(int j = 0; j<8; j++){
				cnt+=(a[i+j]==5);
			}
			if(cnt!=1)return false;
		}
	}
	return true;
}
void f(int k, int val){
	vector<int>a; a.push_back(2);
	if(k>=2)a.push_back(3);
	if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
	if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
	if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
	do{
		if(!check(k,a))continue;
		int v = 0;
		for(int i = 0; i<(1<<(k-1)); i++){
			v+=(i+1)*powers[a[i]]%mod; v%=mod;
		}
		if(v==val){
			for(int i = 0; i<(1<<(k-1)); i++){
				cout << a[i] << " ";
			}
			return;
		}
	}
	while(next_permutation(a.begin(),a.end()));
}
void f2(int k, int val){
	vector<int>a; a.push_back(1);
	if(k>=2)a.push_back(3);
	if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
	if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
	if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
	do{
		if(!check(k,a))continue;
		int v = 0;
		for(int i = 0; i<(1<<(k-1)); i++){
			v+=(i+1)*powers[a[i]]%mod; v%=mod;
		}
		if(v==val){
			for(int i = 0; i<(1<<(k-1)); i++){
				cout << a[i] << " ";
			}
			return;
		}
	}
	while(next_permutation(a.begin(),a.end()));
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int k,A,h;
	cin >> k >> A >> h;
	
	powers[0] = 1;
	for(int i = 1; i<=100; i++){
		powers[i] = powers[i-1]*A; powers[i]%=mod;
	}
	if(true){
		unordered_set<int>s;
		s.rehash(100000);
		if(true){
			vector<int>a; a.push_back(2);
			if(k>=2)a.push_back(3);
			if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
			if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
			if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
			do{
				if(!check(k,a))continue;
				int v = 0;
				for(int i = 0; i<(1<<(k-1)); i++){
					v+=(i+1)*powers[a[i]]%mod; v%=mod;
				}
				s.insert(v);
				//cerr << v << "\n";
			}
			while(next_permutation(a.begin(),a.end()));
		}
		if(true){
			vector<int>a; a.push_back(1);
			if(k>=2)a.push_back(3);
			if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
			if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
			if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
			do{
				if(!check(k,a))continue;
				int v = 0;
				for(int i = 0; i<(1<<(k-1)); i++){
					v+=(i+(1<<(k-1))+1)*powers[a[i]]%mod; v%=mod;
				}
				int nv = h-v; nv+=mod; nv%=mod;
				if(s.count(nv)){
					f(k,nv);
					for(int i = 0; i<(1<<(k-1)); i++){
						cout << a[i] << " ";
					}
					cout << "\n";
					return 0;
				}
				//cerr << "nae\n";
			}
			while(next_permutation(a.begin(),a.end()));
		}
	}
	//cerr << "nae\n";
	if(true){
		unordered_set<int>s;
		s.rehash(1000000);
		if(true){
			vector<int>a; a.push_back(1);
			if(k>=2)a.push_back(3);
			if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
			if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
			if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
			do{
				if(!check(k,a))continue;
				int v = 0;
				for(int i = 0; i<(1<<(k-1)); i++){
					v+=(i+1)*powers[a[i]]%mod; v%=mod;
				}
				s.insert(v);
			}
			while(next_permutation(a.begin(),a.end()));
		}
		if(true){
			vector<int>a; a.push_back(2);
			if(k>=2)a.push_back(3);
			if(k>=3)for(int i = 0; i<2; i++)a.push_back(5);
			if(k>=4)for(int i = 0; i<4; i++)a.push_back(9);
			if(k>=5)for(int i = 0; i<8; i++)a.push_back(17);
			do{
				if(!check(k,a))continue;
				int v = 0;
				for(int i = 0; i<(1<<(k-1)); i++){
					v+=(i+(1<<(k-1))+1)*powers[a[i]]%mod; v%=mod;
				}
				int nv = h-v; nv+=mod; nv%=mod;
				if(s.count(nv)){
					f2(k,nv);
					for(int i = 0; i<(1<<(k-1)); i++){
						cout << a[i] << " ";
					}
					cout << "\n";
					return 0;
				}
			}
			while(next_permutation(a.begin(),a.end()));
		}
	}
	cout << "-1\n";
	return 0;
}