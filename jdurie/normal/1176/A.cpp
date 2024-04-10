#include <bits/stdc++.h>

using namespace std;

#define init int i,j; ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lli long long int
#define pi pair<int,int>
#define pl pair<lli,lli>
#define uset unordered_set
#define umap unordered_map
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(group) group.begin(), group.end()
#define F(i,l,r) for(i=l; i!=r; r>l?i++:i--)
#define fill(arr,n) FOR(i,0,n) cin >> arr[i];
#define fill2D(arr2D,r,c) FOR(i,0,r){ fill(arr[i],c) }
#define pr(x) cout << #x << ": " << x << "\n";
#define prArr(arr,n) FOR(i,0,n) cout << arr[i] << " "; cout << "\n";
#define prArr2D(arr2D,r,c) FOR(i,0,r){ prArr(arr2D[i],c); } 
#define G umap<int,uset<int>>
#define getEdges(gr,m,i) int a,b; FOR(i,0,m) { cin >> a >> b; gr[a-1].insert(b-1); gr[b-1].insert(a-1); }
#define P complex
#define X real()
#define Y imag()

int main(){
    init
    int q,ans;
    lli n;
    cin >> q;
    F(i,0,q){
        cin >> n;
        ans=0;
        while(n%2==0){
            ans++;
            n/=2;
        }
        while(n%3==0){
            ans+=2;
            n/=3;
        }
        while(n%5==0){
            ans+=3;
            n/=5;
        }
        cout << (n==1?ans:-1) << endl;
    }
    return 0;
}