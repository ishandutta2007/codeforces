#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define breaker if(cursor > cnt){sum = sum + (cnt + 1 - node + 1) / 2; break;}
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
const ll mod = 1e9 + 7;
const int maxN = 200005;
const ll oo = 1e18 + 7;
int n, temp, temp1; char vdf; bool bt[maxN];
int ray[maxN]; int cnt; int cursor; int raycur; int prefix[maxN]; int node;



int main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n; cnt = 0; cursor = 0;
        for(int i = 1; i <= n; i++){
            cin >> vdf; temp = vdf - 48; bt[i] = temp;
        }
        bt[n + 1] = !temp; temp = 1; n++;
        for(int i = 2; i <= n; i++){
            if(bt[i] != bt[i - 1]){cnt++; ray[cnt] = temp; temp = 1;}
            else{temp++;}
        } n--; cursor = 1; node = 1;
        // job: cursor go to the delete point; cout prefix of cursor - prefix current;
        int sum = 0; // node is the current position
        // 6 4 2 1 3 1 1 
        while(cursor <= cnt){
            breaker 
            while(ray[cursor] == 1) cursor++;
            breaker
            if(node == cursor){
                if(ray[cursor] > 1){ sum++; node++; cursor++; continue;}
                else cout << "BUG";
            }
            breaker
            ray[cursor]--; sum++; node++;
            breaker
        }
        cout << sum << '\n';
    }
}