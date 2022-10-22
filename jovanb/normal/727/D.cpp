#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int ima[7];
vector <int> treba[7];
vector <int> jedan[7];
int res[100005];

string koji[] = {"", "S", "M", "L", "XL", "XXL", "XXXL"};

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    for(int i=1; i<=6; i++){
        cin >> ima[i];
    }
    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        string s;
        cin >> s;
        if(s == "S"){
            jedan[1].push_back(i);
        }
        else if(s == "M"){
            jedan[2].push_back(i);
        }
        else if(s == "L"){
            jedan[3].push_back(i);
        }
        else if(s == "XL"){
            jedan[4].push_back(i);
        }
        else if(s == "XXL"){
            jedan[5].push_back(i);
        }
        else if(s == "XXXL"){
            jedan[6].push_back(i);
        }
        else if(s == "S,M"){
            treba[2].push_back(i);
        }
        else if(s == "M,L"){
            treba[3].push_back(i);
        }
        else if(s == "L,XL"){
            treba[4].push_back(i);
        }
        else if(s == "XL,XXL"){
            treba[5].push_back(i);
        }
        else if(s == "XXL,XXXL"){
            treba[6].push_back(i);
        }
    }
    for(int i=1; i<=6; i++){
        for(auto c : jedan[i]){
            res[c] = i;
            ima[i]--;
        }
        if(ima[i] < 0){
            cout << "NO";
            return 0;
        }
    }
    for(int i=2; i<=6; i++){
        while(ima[i-1] && treba[i].size()){
            int k = treba[i][treba[i].size()-1];
            treba[i].pop_back();
            res[k] = i-1;
            ima[i-1]--;
        }
        while(ima[i] && treba[i].size()){
            int k = treba[i][treba[i].size()-1];
            treba[i].pop_back();
            res[k] = i;
            ima[i]--;
        }
        if(treba[i].size()){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(int i=1; i<=q; i++){
        cout << koji[res[i]] << "\n";
    }
    return 0;
}