#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
string s[1000100];
vector<int> children[1000100];
int value[1000100];
int crucial[1000100];

void visit(int k)
{
    if(value[k] != -1){
        return;
    }
    for(int i = 0; i < children[k].size(); i++){
        visit(children[k][i]);
    }
    char check = s[k][0];
    if(check == 'A'){
        value[k] = value[children[k][0]] and value[children[k][1]];
    }
    if(check == 'O'){
        value[k] = value[children[k][0]] or value[children[k][1]];
    }
    if(check == 'X'){
        value[k] = value[children[k][0]] xor value[children[k][1]];
    }
    if(check == 'N'){
        value[k] = 1 - value[children[k][0]];
    }
    return;
}

void visit2(int k)
{
    if(s[k][0] == 'I'){
        return;
    }
    if(s[k][0] == 'A'){
        for(int l = 0; l <= 1; l++){
            if(value[k] == 1){
                crucial[children[k][l]] = 1;
            } else {
                crucial[children[k][l]] = (value[children[k][0]] or value[children[k][1]]) and (1 - value[children[k][l]]);
            }
        }
    }
    if(s[k][0] == 'O'){
        for(int l = 0; l <= 1; l++){
            if(value[k] == 0){
                crucial[children[k][l]] = 1;
            } else {
                crucial[children[k][l]] = (((1 - value[children[k][0]]) or (1 - value[children[k][1]])) and (value[children[k][l]]));
            }
        }
    }
    if(s[k][0] == 'X'){
        for(int l = 0; l <= 1; l++){
            crucial[children[k][l]] = 1;
        }
    }
    if(s[k][0] == 'N'){
        crucial[children[k][0]] = 1;
    }
    for(int l = 0; l < children[k].size(); l++){
        crucial[children[k][l]] = crucial[children[k][l]] and crucial[k];
        visit2(children[k][l]);
    }
}

int main() {
    //cout.precision(10);
    int n;
    cin >> n;
    for(int i = 0; i <= 1000000; i++){
        value[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        int in1, in2;
        cin >> s[i] >> in1;
        if(s[i][0] == 'I'){
            value[i] = in1;
            continue;
        }
        children[i].push_back(in1);
        if(!(s[i][0] == 'N' || s[i][0] == 'I')){
            cin >> in1;
            children[i].push_back(in1);
        }
    }
    visit(1);
    /*for(int i = 1; i <= n; i++){
        cout << i << " " << value[i] << endl;
    }
    cout << "crucial" << endl;*/
    crucial[1] = 1;
    visit2(1);
    /*for(int i = 1; i <= n; i++){
        cout << i << " " << crucial[i] << endl;
    }*/
    for(int i = 1; i <= n; i++){
        if(s[i][0] != 'I'){
            continue;
        }
        cout << (value[1] + crucial[i]) % 2;
    }
    cout << endl;
    return 0;
}