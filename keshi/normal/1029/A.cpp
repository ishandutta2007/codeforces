/******************************** In the name of GOD *****************************/
#include<bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define sep                         ' '
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define error(x)                    cerr << "$$$ " << x << '\n';
#define error2(x,y)                 cerr << "#F : " << x << "      #S : " << y << '\n';
#define pb                          push_back

const ll MX5 = 3*1e5+3;
const ll MX6 = 1*1e6+37;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
const ll MOD2= 998244353;

ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
ll bmm(ll a,ll b){
    return (a%b==0 ? b : bmm(b,a%b));
}

ll A[MX5];

int main(){
    fast_io
    //file_io
    ll n,k;
    string s;
    cin >> n >> k >> s;
    string ans=s;
    k--;
    while(k--){
        ll last=-1;
        for(int i=ans.size()-n+1;i<ans.size();i++){
            bool f=1;
            for(int j=i;j<ans.size();j++){
                if(s[j-i]!=ans[j]) f=0;
            }
            if(f){
                last=i;
                break;
            }
        }
        //error(last)
        if(last==-1){
            ans+=s;
        }
        else{
            ans=ans.substr(0,last);
            ans+=s;
        }
    }
    cout << ans;


    return 0;
}

/*!
NNNNNNNN        NNNNNNNN IIIIIIIIII MMMMMMMM               MMMMMMMM                AAA
N;;;;;;;N       N;;;;;;N I::::::::I M;;;;;;;M             M;;;;;;;M               A:::A
N;;;;;;;;N      N;;;;;;N I::::::::I M;;;;;;;;M           M;;;;;;;;M              A\N.N/A
N;;;;;;;;;N     N;;;;;;N II::::::II M;;;;;;;;;M         M;;;;;;;;;M             A:::::::A
N;;;;;;;;;;N    N;;;;;;N   I::::I   M;;;;;;;;;;M       M;;;;;;;;;;M            A:::::::::A
N;;;;;;;;;;;N   N;;;;;;N   I::::I   M;;;;;;;;;;;M     M;;;;;;;;;;;M           A:::::A:::::A
N;;;;;;;N;;;;N  N;;;;;;N   I::::I   M:::::::M;;;;M   M;;;;M;;;;;;;M          A:::::A A:::::A
N;;;;;;N N;;;;N N;;;;;;N   I::::I   M;;;;;;M M;;;;M M;;;;M M;;;;;;M         A:::::A   A:::::A
N;;;;;;N  N;;;;N;;;;;;;N   I::::I   M;;;;;;M  M;;;;M;;;;M  M;;;;;;M        A:::::A     A:::::A
N;;;;;;N   N;;;;;;;;;;;N   I::::I   M;;;;;;M   M\\N.N//M   M;;;;;;M       A:::::AAAAAAAAA:::::A
N;;;;;;N    N;;;;;;;;;;N   I::::I   M;;;;;;M    M;;;;;M    M;;;;;;M      A:::In GOD we trust:::A
N;;;;;;N     N;;;;;;;;;N   I::::I   M;;;;;;M     MMMMM     M;;;;;;M     A:::::AAAAAAAAAAAAA:::::A
N;;;;;;N      N;;;;;;;;N II::::::II M;;;;;;M               M;;;;;;M    A:::::A             A:::::A
N;;;;;;N       N;;;;;;;N I::::::::I M;;;;;;M               M;;;;;;M   A:::::A               A:::::A
N;;;;;;N        N;;;;;;N I::::::::I M;;;;;;M               M;;;;;;M  A:::::A                 A:::::A
NNNNNNNN         NNNNNNN IIIIIIIIII MMMMMMMM               MMMMMMMM AAAAAAA                   AAAAAAA
*/