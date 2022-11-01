#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
struct Rule{
    string p;
    int l, r;
};
string s;
int nrule;
Rule rules[10];
bool complies(string& t, string& p, int& l, int& r){
     int pos = 0, ocr = 0;
     while( (pos = p.find(t, pos)) != string::npos )
         pos++, ocr++;
     // cout << ocr << endl;
     return l <= ocr && ocr <= r;
}
bool complies(string& t, Rule& r){
     return complies(t, r.p, r.l, r.r);
}
int main(){
    cin >> s >> nrule;
    for(int i = 0; i < nrule; i++)
        cin >> rules[i].p >> rules[i].l >> rules[i].r;
    int ocr = 0;
    for(int l = 0; l < s.length(); l++)
        for(int r = l; r < s.length(); r++){
            string sub = s.substr(l, r - l + 1);
            if(s.find(sub) == l){
                int i;
                for( i = 0; i < nrule; i++){
                    if(!complies(sub, rules[i]))
                        break;
                }
                if( i == nrule ){
                    ocr++;
                    // cout << "found" << l <<","<<r<<endl;
                }
            }
        }
    cout << ocr << endl;
    // system("pause");
    return 0;
}