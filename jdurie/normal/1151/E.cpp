#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ld long double
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ifstream cin ("/Users/Aulene/Desktop/input.txt");
    // ofstream cout ("/Users/Aulene/Desktop/output.txt");

    // ifstream cin ("input.txt");
    // ofstream cout ("output.txt");
    
    // ifstream cin ("usaco.in");
    // ofstream cout ("usaco.out");
    
    int n,last,next,ans=0;
    cin >> n;
    cin >> last;
    for(int i=1;i<n;i++){
        cin >> next;
        if(next!=last){
            ans-=min(next,last)*(n-max(next,last)+1);
            ans+=last*(n-last+1);
        }
        last=next;
    }    
    ans+=last*(n-last+1);
    cout << ans;
}