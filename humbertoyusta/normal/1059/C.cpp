/**	Name: Humberto Yusta Gomez
	Grado: 11no
	Prov: Villa Clara */
#include<bits/stdc++.h>
#define maxn 100010
#define inf 1000000007
#define ii pair<int,int>
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define less(n) order_of_key(n)
#define kth(n) find_by_order(n)
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,ans;
ordered_set s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    if( n == 1 ){ cout << 1; return 0; }
    if( n == 2 ){ cout << 1 << ' ' << 2; return 0; }

    for(int i=1; i<=n; i++){
        s.insert(i);
    }

    ans = 1;
    while( s.size() > 3 ){
        for(int i=0; i<s.size(); i++){
            if( s.size() == 3 ) break;
            s.erase(s.kth(i));
            cout << ans << ' ';
        }
        ans *= 2;
    }

    int arr[3],cont = 0;
    for(auto i : s)
        arr[cont++]=i;

    cout << __gcd( arr[0] , __gcd( arr[1] , arr[2] ) ) << ' ';

    if( __gcd(arr[0],arr[1]) > __gcd(arr[0],arr[2]) && __gcd(arr[0],arr[1]) > __gcd(arr[1],arr[2]) ){
        cout << __gcd(arr[0],arr[1]) << ' ' << arr[1];
    }
    else{
        cout << max( __gcd(arr[0],arr[2]) , __gcd(arr[1],arr[2]) ) << ' ' << arr[2];
    }

    return 0;
}