#include <bits/stdc++.h>
using namespace std;

int n;

queue <int> q;

string s1, s2;

void shiftuj(int x){
    q.push(x);
    string str1="", str2="";
    for(int i=n-1; i>=n-x; i--){
        str1 += s1[i];
    }
    for(int i=0; i<n-x; i++){
        str2 += s1[i];
    }
    s1 = str1+str2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n;
    cin >> s1 >> s2;
    string ss1, ss2;
    ss1 = s1;
    ss2 = s2;
    sort(ss1.begin(), ss1.end());
    sort(ss2.begin(), ss2.end());
    if(ss1 != ss2){cout << -1; return 0;}
    for(int i=n-1; i>0; i--){
        char x = s2[i];
        for(int j=n-1-i; j<n; j++){
            if(s1[j] == x){
                shiftuj(n);
                if(j > 0)shiftuj(j);
                shiftuj(1);
                break;
            }
        }
    }
    shiftuj(1);
    cout << q.size() << "\n";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}