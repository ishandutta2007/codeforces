#include <iostream>
#include <string>
using namespace std;

int ask(int x, int y)
{
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    if (s == "white") return 0;
    else return 1;
}

int sc;
bool f = false;
void bs(int s, int e, int n)
{
    int md = (s + e) / 2;
    if (n <= 0){
        if (f) cout<<md<<" "<<0<<" "<<0<<" "<<999999999<<'\n';
        else cout<<md<<" "<<0<<" "<<md<<" "<<1<<'\n';
        return;
    }
    int t = ask(md, 0);
    if (t == sc) bs(md + 1, e, n - 1);
    else bs(s, md - 1, n - 1);
}

int main()
{
    int n;
    cin>>n;
    sc = ask(0, 0);
    if (n >= 2){
        int t = ask(0, 1000000000);
        if (t != sc) f = true;
    }
    bs(1, 1000000000, n - 2);
    return 0;
}