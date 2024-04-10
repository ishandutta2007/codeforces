#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
const ll mod = 1000000007;
int prm[1000005]; // prm[i] is prime i'th, like 1st, 2nd...
bool chk[1000005]; // the check row, to see if i is a prime or not

int main(){
    ios_base::sync_with_stdio(0);
	int cnt = 0;
	for(int i = 0; i <= 1000000; i++){
	    chk[i] = 1;
	}
	for(int i = 2; i <= 1000000; i++){
	    if(chk[i]){
	        prm[cnt] = i; cnt++;
	        for(int j = 2 * i; j <= 1000000; j += i){
	            chk[j] = 0;
	        }
	    }
	}
	int arr[100000];
	int o; cin >> o;
	while(o--){
	    int n; cin >> n;
	    if(n % 2 == 1){
	        for(int i = 1; i <= n - 1; i++){
	            arr[i] = 1;
	        }
	        int cur;
	        for(int i = 1; i <= 100000; i++){
	            if(chk[i] == 0 && chk[n - 1 + i] == 1){
	                cur = i; break;
	            }
	        }
	        arr[n] = cur;
	        for(int i = 1; i <= n; i++){
	            for(int j = 1; j <= n; j++){
	                if(i == j) cout << cur;
	                else cout << 1;
	                cout << " ";
	            }
	            cout << endl;
	        }
	    }
	    else{
	        for(int i = 1; i <= n - 1; i++){
	            arr[i] = 1;
	        }
	        int cur;
	        for(int i = 1; i <= 100000; i++){
	            if(chk[i] == 0 && chk[n - 1 + i] == 1){
	                cur = i; break;
	            }
	        }
	        arr[n] = cur;
	        for(int i = 1; i <= n; i++){
	            for(int j = 1; j <= n; j++){
	                if(i == j) cout << cur;
	                else cout << 1;
	                cout << " ";
	            }
	            cout << endl;
	        }
	    }
	}
	
}