#include <iostream>
#include <vector>

using namespace std;

enum Symbol{
    big, small, be, se
};

istream& operator >> (istream& in, Symbol& s){
    char c; in >> c;
    char d = in.get();
    if(d == '='){
        s = c == '>' ? be : se;
    } else {
        s = c == '>' ? big : small;
    }
    return in;
}

int main() {
    unsigned n; cin >> n;
    int first = -2000000000, last = 2000000001;
    while(n--){
        Symbol s; int x; char c; cin >> s >> x >> c;
        if(s == big){
            s = be;
            x++;
        } else if (s == se){
            s = small;
            x++;
        }
        if(c == 'N'){
            s = s == be ? small : be;
            c = 'Y';
        }
        if(s == small){
            last = min(last, x);
        } else {
            first = max(first, x);
        }
    }
    if(first < last){
        cout << first << endl;
    } else {
        cout << "Impossible" << endl;
    }
}