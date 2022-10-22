#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q){
        q --;
        int k,res=0,c=0;
        string s;
        cin >> k >> s;
        bool beh = false;
        for (int i = 0; i < k; i++){
            if (s[i] == 'A') beh = true;
            if (beh || s[i] == 'P'){
                if (s[i] == 'P' && beh) c ++;
                if (c > res) res = c;
                if (s[i] == 'A') c = 0;
            }
        }
        cout << res << endl;
    }
}