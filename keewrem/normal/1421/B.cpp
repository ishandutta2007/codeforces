#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        string s[N];
        for(int i = 0; i < N; i++)cin >> s[i];
        if(s[0][1]==s[1][0]){
            if( s[N-1][N-2]==s[0][1]){
                if(s[N-1][N-2]==s[N-2][N-1]){
                    cout << "2\n" << N << " "<<N-1 <<"\n"<<N-1<<" "<<N <<"\n"; continue;
                }else{
                    cout << "1\n"<<N << " "<<N-1<<"\n"; continue;
                }
            }else{
                if(s[N-1][N-2]==s[N-2][N-1]){
                    cout << "0\n"; continue;
                }else{
                    cout << "1\n"<< N-1<<" "<<N<<"\n";
                }
            }
        }else{
            if(s[N-1][N-2]==s[0][1]){
                if(s[N-1][N-2]==s[N-2][N-1]){
                    cout << "1\n 1 2\n";
                }else{
                    cout << "2\n 1 2\n"<<N-1<<" "<<N<<"\n";
                }
            }else{
                if(s[N-1][N-2]==s[N-2][N-1]){
                    cout << "1\n 2 1\n";
                }else{
                    cout << "2\n"<<N << " "<<N-1<<"\n"<<"1 2\n"; continue;
                }
            }
        }
    }
    return 0;
}