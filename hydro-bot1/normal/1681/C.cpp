// Hydro submission #62c7c835c3a9fda5622c48ee@1657260085757
#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define fo(i,n) for(ll i=0;i<n;i++)
#define fox(i,k,n) for(ll i=k;i<n;i++)
#define CE cout<<endl
#define CEL(x) cout<<x<<endl
#define CEsp(x) cout<<x<<' '
#define Jai ios_base::sync_with_stdio(false);
#define Shree cin.tie(NULL);
#define Ram cout.tie(NULL);
const long double pi = std::acos(-1);
using namespace std;
bool is_array_sorted(int *a, int leng){
	int b[leng];
	fo(i,leng) b[i]=a[i];
	sort(b,b+leng);
	fo(i,leng) if(a[i]!=b[i]) return false;
	return true;
}
int main(){
	Jai Shree Ram
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n],b[n],asort[n],bsort[n];
		std::vector<pair<int,int>> av,bv;
		fo(i,n) {cin>>a[i]; asort[i]=a[i];}
		fo(i,n) {cin>>b[i]; bsort[i]=b[i];}
		sort(asort,asort+n);
		sort(bsort,bsort+n);
		std::vector<pair<int, int>> res; int cnt=0;
		bool printed=false;
		for(int i=0;i<n;i++){
			if(a[i]!=asort[i]){
				bool f=false;
				for(int j=i+1;j<n;j++){
					if(a[j]==asort[i] && b[j]==bsort[i]){
						cnt++; f=true;
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						res.pb({i+1,j+1});
						break;
					}
				}
				if(!f){
					printed = true; break;
				}
			}else if(b[i]!=bsort[i]){
				bool f=false; f=true;
				for(int j=i+1;j<n;j++){
					if(b[j]==bsort[i] && a[j]==asort[i]){
						cnt++;
						swap(a[i],a[j]);
						swap(b[i],b[j]);
						res.pb({i+1,j+1});
						break;
					}
				}if(!f){
					printed = true; break;
				}
			}
		}
		if(is_array_sorted(a,n) && is_array_sorted(b,n) && !printed){
			CEL(cnt);
			for(pair<int,int>p:res) cout<<p.F<<' '<<p.S<<endl;
		}else CEL(-1);
	}
	return 0;
}