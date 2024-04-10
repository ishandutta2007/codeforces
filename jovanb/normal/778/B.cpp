#include <bits/stdc++.h>
using namespace std;

int m, br1[10000], br0[10000];

unordered_map <string, int> hes;
char val1[10000][10000];
char val0[10000][10000];

void aand(string a, string b, string c){
    char bb, cc;
    if(b == "?" && c == "?"){
        for(int i=0; i<m; i++){
            val1[hes[a]][i] = '1';
            val0[hes[a]][i] = '0';
            br1[i]++;
         }
    }
    else if(b != "?" && c != "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            cc = val1[hes[c]][i];
            if(bb == '1' && cc == '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            bb = val0[hes[b]][i];
            cc = val0[hes[c]][i];
            if(bb == '1' && cc == '1'){br0[i]++; val0[hes[a]][i] = '1';}
            else val0[hes[a]][i] = '0';
        }
    }
    else if(c == "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            if(bb == '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            val0[hes[a]][i] = '0';
        }
    }
    else{
        for(int i=0; i<m; i++){
            cc = val1[hes[c]][i];
            if(cc == '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            val0[hes[a]][i] = '0';
        }
    }
}

void oor(string a, string b, string c){
    char bb, cc;
    if(b == "?" && c == "?"){
        for(int i=0; i<m; i++){
            val1[hes[a]][i] = '1';
            val0[hes[a]][i] = '0';
            br1[i]++;
         }
    }
    else if(b != "?" && c != "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            cc = val1[hes[c]][i];
            if(bb == '1' || cc == '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            bb = val0[hes[b]][i];
            cc = val0[hes[c]][i];
            if(bb == '1' || cc == '1'){br0[i]++; val0[hes[a]][i] = '1';}
            else val0[hes[a]][i] = '0';
        }
    }
    else if(c == "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            br1[i]++;
            val1[hes[a]][i] = '1';
            bb = val0[hes[b]][i];
            if(bb == '1'){val0[hes[a]][i] = '1'; br0[i]++;}
            else val0[hes[a]][i] = '0';
        }
    }
    else{
        for(int i=0; i<m; i++){
            cc = val1[hes[c]][i];
            br1[i]++;
            val1[hes[a]][i] = '1';
            cc = val0[hes[c]][i];
            if(cc == '1'){val0[hes[a]][i] = '1'; br0[i]++;}
            else val0[hes[a]][i] = '0';
        }
    }
}

void xoor(string a, string b, string c){
    char bb, cc;
    if(b == "?" && c == "?"){
        for(int i=0; i<m; i++){
            val1[hes[a]][i] = '0';
            val0[hes[a]][i] = '0';
         }
    }
    else if(b != "?" && c != "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            cc = val1[hes[c]][i];
            if(bb != cc){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            bb = val0[hes[b]][i];
            cc = val0[hes[c]][i];
            if(bb != cc){br0[i]++; val0[hes[a]][i] = '1';}
            else val0[hes[a]][i] = '0';
        }
    }
    else if(c == "?"){
        for(int i=0; i<m; i++){
            bb = val1[hes[b]][i];
            if(bb != '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            bb = val0[hes[b]][i];
            if(bb != '0'){br0[i]++; val0[hes[a]][i] = '1';}
            else val0[hes[a]][i] = '0';
        }
    }
    else{
        for(int i=0; i<m; i++){
            cc = val1[hes[c]][i];
            if(cc != '1'){br1[i]++; val1[hes[a]][i] = '1';}
            else val1[hes[a]][i] = '0';
            cc = val0[hes[c]][i];
            if(cc != '0'){br0[i]++; val0[hes[a]][i] = '1';}
            else val0[hes[a]][i] = '0';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    int drd = -1;
    cin >> n >> m;
    while(n--){
        string stren;
        cin >> stren;
        hes[stren] = ++drd;
        string bespotrebno;
        cin >> bespotrebno;
        string x;
        cin >> x;
        if(x[0] == '1' || x[0] == '0') {
            for(int nesto=0; nesto<m; nesto++) {
                val1[hes[stren]][nesto] = x[nesto];
                val0[hes[stren]][nesto] = x[nesto];
            }
            continue;
        }
        string kom, y;
        cin >> kom >> y;
        if(kom == "AND") aand(stren, x, y);
        if(kom == "OR") oor(stren, x, y);
        if(kom == "XOR") xoor(stren, x, y);
    }
    string str;
    for(int i=0; i<m; i++){
        if(br1[i] < br0[i]) str += "1";
        else str += "0";
    }
    cout << str << endl;
    str = "";
    for(int i=0; i<m; i++){
        if(br1[i] > br0[i]) str += "1";
        else str += "0";
    }
    cout << str;
    return 0;
}