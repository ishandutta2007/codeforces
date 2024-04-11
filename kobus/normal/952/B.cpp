#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX
#define MOD 1000000007
#define cte 10002
#define MAX ULLONG_MAX


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    cout.setf(ios::fixed);

    int n=0;
    int nos=0;
    while(true){
    	cout<<n<<endl;
    	n++;
    	string s;
    	getline(cin,s);
    	if(s=="no"){
    		nos++;
    		if(nos>3){
    			cout<<"normal"<<endl;
    			return 0;
    		}
    		continue;
    	}
    	if(s=="great" || s=="not bad" || s=="don't touch me" || s=="don't think so" || s=="cool"){
    		cout<<"normal"<<endl;
    		return 0;
    	}
    	else{
    		cout<<"grumpy"<<endl;
    		return 0;
    	}
    }

    return 0;

}