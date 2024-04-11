#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> w;

int main(){
int n;
cin >> n;
set<w> s;
while(n--){
w x;
cin >> x.first >> x.second;
s.insert(x);
}
cout << s.size();
}