#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;

int main(){
    string s;
    cin >> s;
    while(true){
        int idx = s.find("WUB");
        if(idx == string::npos) break;
        s.replace(idx, 3, "   ");
    }
    stringstream ss(s);
    vector<string> answer;
    while(ss >> s) answer.push_back(s);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];
        if(i == answer.size() - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}