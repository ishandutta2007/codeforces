#include<bits/stdc++.h>
using namespace std;
int n,t;
bool p[204];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int B[n];
        for(int i =0; i < 201; i++)p[i]=0;
        for(int i = 0; i < n; i++){
            cin >> B[i];
            p[B[i]]=1;
        }
        vector <int> sol;
        bool sus = 0;
        for(int j = 0; j < n; j++){
            sol.push_back(B[j]);
            for(int i = B[j]+1; 1; i++){
                if(i>2*n){cout<<"-1\n";sus = 1;break;}
                if(!p[i]){
                    sol.push_back(i);
                    p[i]=1;
                    break;
                }
            }
            if(sus)break;
        }
        if(sus)continue;
        for(auto x: sol)cout << x << " ";
        cout << "\n";

    }
    return 0;
}