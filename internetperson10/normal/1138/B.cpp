#include <bits/stdc++.h>

using namespace std;

vector<int> neither;
vector<int> both;
vector<int> clowns;
vector<int> acrobats;

int main() {
    int l, k;
    string sc, sa;
    cin >> l;
    cin >> sc >> sa;
    for(int a=0; a<l; a++) {
        k = (int)(sc.at(a)-'0'+sa.at(a)-'0');
        if(k==0) neither.push_back(a+1);
        else if(k==2) both.push_back(a+1);
        else if(sc.at(a)=='1') clowns.push_back(a+1);
        else acrobats.push_back(a+1);
    }
    //cout << neither.size() << ' ' << both.size() << ' ' << clowns.size() << ' ' << acrobats.size() << '\n';
    bool found = false;
    for(int b=0; b<=both.size() && !found; b++) {
        for(int c=0; c<=clowns.size() && !found; c++) {
            int a=acrobats.size()+both.size()-2*b-c;
            int neit=l/2-a-b-c;
            //cout << neit << ' ' << a << ' ' << c << ' ' << b << '\n';
            if(a>-1 && a<=acrobats.size() && neit>-1 && neit<=neither.size()) {
                //cout << "yay!";
                for(int x=0; x<a; x++) {
                    cout << acrobats[x] << ' ';
                }
                for(int x=0; x<b; x++) {
                    cout << both[x] << ' ';
                }
                for(int x=0; x<c; x++) {
                    cout << clowns[x] << ' ';
                }
                for(int x=0; x<neit; x++) {
                    cout << neither[x] << ' ';
                }
                found = true;
            }
        }
    }
    if(!found) cout << "-1";
}