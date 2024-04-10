#include <iostream>

using namespace std;

int n;
string in;

string base[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(){
    cin >> n >> in;
    for (int i = 0; i < 8; ++i){
        if (base[i].size() != in.size()) continue;
        bool ch = true;
        for (int j = 0; j < in.size(); ++j){
            if (in[j] == '.') continue;
            if (in[j] != base[i][j]) ch = false;
        }
        if (ch) cout << base[i] << endl;
    }
    return 0;
}