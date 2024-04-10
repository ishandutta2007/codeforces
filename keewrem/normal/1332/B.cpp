#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll T,N,K;
ll sas[11]={2,3,5,7,11,13,17,19,23,29,31};
ll sos[10000];
ll res[10000];
bool preso[11];
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++)cin >> sos[i];
        int c =0;
        for(int i = 0; i < 11; i++)preso[i]=0;
        for(int i = 0; i < N; i++){
            for(int  j= 0; j < 11; j++){
                if(sos[i]%sas[j]==0){
                    res[i]=j;
                    if(!preso[j])c++;
                    preso[j]=1;
                    break;
                }
            }
        }
        int sus[11];
        int last = 1;
        for(int i = 0; i < 11; i++){
            sus[i]=last;
            if(preso[i])last++;
        }
        cout << c<<"\n";
        for(int i = 0; i < N; i++){
            cout << sus[res[i]] << " ";
        }
        cout << "\n";
    }
    return 0;
}