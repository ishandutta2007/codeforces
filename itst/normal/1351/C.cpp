#include<bits/stdc++.h>
using namespace std;

int main(){
int T; string s;
for(cin >> T ; T ; --T){
cin >> s;set < pair < int , int > > id; int x = 0 , y = 0 , ans = 0 , px = 0 , py = 0;
for(auto t : s){
    px = x; py = y;
switch(t){
case 'N': ++y; break;
case 'S': --y; break;
case 'W': ++x; break;
case 'E': --x; break;
}
if(id.find(make_pair(x + px , y + py)) == id.end()){ans += 5; id.insert(make_pair(x + px , y + py));}
else ++ans;
}
cout << ans << endl;
}
return 0;
}