#include <bits/stdc++.h>

using namespace std;
vector<int> hour;
vector<int> minute;
int main() {
    int minallowed=2, maxallowed=60;
    bool isHour=true;
    string s;
    cin >> s;
    for(int a=0; a<s.size(); a++) {
        if(s.at(a)==':') {
            isHour=false;
            for(int x=2; x<=24; x++) {
                int s=0;
                for(int y=0; y<hour.size(); y++) {
                    s+=(hour[y])*(pow(x, hour.size()-y-1));
                }
                if(s>23) {
                    maxallowed=min(maxallowed, x-1);
                    break;
                }
            }
            vector<int>().swap(hour);
        }
        else {
            if(s.at(a)>='A') hour.push_back((int)s.at(a)-'A'+10);
            else hour.push_back((int)s.at(a)-'0');
            if(hour[hour.size()-1]==0 && hour.size()==1) {
                hour.pop_back();
            }
            else {
                minallowed=max(minallowed, hour[hour.size()-1]+1);
                //cout << hour[hour.size()-1] << ' ' << minallowed << ' ' << maxallowed << '\n';
            }
        }
    }
    for(int x=2; x<=60; x++) {
        int s=0;
        for(int y=0; y<hour.size(); y++) {
            s+=(hour[y])*(pow(x, hour.size()-y-1));
        }
        if(s>59) {
            maxallowed=min(maxallowed, x-1);
            break;
        }
    }
    vector<int>().swap(hour);
    if(maxallowed==60) {
        cout << "-1";
    }
    else if(minallowed>maxallowed) {
        cout << "0";
    }
    else for(int a=minallowed; a<=maxallowed; a++) {
        cout << a << ' ';
    }
}