#include <bits/stdc++.h>
using namespace std;

map < string, string > stone;

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    stone["purple"] = "Power";
    stone["green"] = "Time";
    stone["blue"] = "Space";
    stone["orange"] = "Soul";
    stone["red"] = "Reality";
    stone["yellow"] = "Mind";
    string in;

    cin >> N;
    int M = 6-N;
    while(N--){
        cin >> in;
        stone[in] = "0";
    }
    cout << M << "\n";
    if(stone["purple"]!="0") cout << stone["purple"] << "\n";
    if(stone["green"]!="0") cout << stone["green"] << "\n";
    if(stone["blue"]!="0") cout << stone["blue"] << "\n";
    if(stone["orange"]!="0") cout << stone["orange"] << "\n";
    if(stone["red"]!="0") cout << stone["red"] << "\n";
    if(stone["yellow"]!="0") cout << stone["yellow"] << "\n";

    return 0;
}