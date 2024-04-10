#include <bits/stdc++.h>
using namespace std;

bool query(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    string s;
    cin >> s;
    return s == "YES";
}

int main(){

    int n;
    cin >> n;
    int i=1, j=1;
    queue <char> q;
    stack <char> stek;
    while((n-i) + (n-j) > n-1){
        if(i < n){
            if(query(i+1, j, n, n)){
                q.push('D');
                i++;
            }
            else{
                j++;
                q.push('R');
            }
        }
        else{
            j++;
            q.push('R');
        }
    }
    i = n;
    j = n;
    while(i-1 + j-1 > n-1){
        if(j > 1){
            if(query(1, 1, i, j-1)){
                stek.push('R');
                j--;
            }
            else{
                i--;
                stek.push('D');
            }
        }
        else{
            i--;
            stek.push('D');
        }
    }
    cout << "! ";
    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    while(!stek.empty()){
        cout << stek.top();
        stek.pop();
    }
    cout << endl;
    return 0;
}