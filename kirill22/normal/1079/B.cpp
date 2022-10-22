#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    int y=0;
    int n=s.size();
    if (n%20==0){
        cout << n/20 << " " << 20 << endl;
        for(int i=0;i<n/20;i++){
            for(int u=0;u<20;u++){
                cout << s[y];
                y++;
            }
            cout << endl;
        }
        return 0;
    }
    int ii=min(5,(n/20+1));
    cout << ii << " ";
    if (n%ii==0){
            cout << n/ii << endl;;
        for(int i=0;i<ii;i++){
            for(int u=0;u<n/ii;u++){
                cout << s[y];
                y++;
            }
            cout << endl;
        }
        return 0;
    }
    int co=ii-n%ii;
    cout << n/ii+1 << endl;
    for(int i=0;i<ii;i++){
        for(int u=0;u<n/ii+1;u++){
            if (u==n/ii && co>0){
                cout << "*";
                co--;
            }

            else{
                cout << s[y];
                y++;
            }
        }
        cout << endl;
    }





    return 0;
}