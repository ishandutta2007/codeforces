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
    int n,rem,k;
    cin >> n;
    rem=0;
    int m[6]={4,8,15,16,23,42};
    int arr[6]={0,0,0,0,0,0};
    F(i,0,n){
        cin >> k;
        if(k==m[0])
            arr[0]++;
        else{
            F(j,1,6){
                if(k==m[j]&&arr[j-1]==0)
                    rem++;
                else if(k==m[j]){
                    arr[j-1]--;
                    arr[j]++;
                }
            }
        }
    }
    F(i,0,5)
        rem+=(i+1)*arr[i];
    cout << rem;
    return 0;
}