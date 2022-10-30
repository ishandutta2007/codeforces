// Hydro submission #612121ce77836383ee6a931e@1662508623490
// Version 2.4.0 by Eason_AC(CJ-wyf)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <set>
#include <queue>
#define Tl template<typename T>
#define F(T, i, a, b) for(T (i) = (a); (i) <= (b); ++(i))
#define R(T, i, a, b) for(T (i) = (a); (i) >= (b); --(i))
#define Fo(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) += (c))
#define Re(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) -= (c))
#define For(T, i, a, b, c) for(T (i) = (a); (i) <= (b); (i) *= (c))
#define Rep(T, i, a, b, c) for(T (i) = (a); (i) >= (b); (i) /= (c))
#define E for(int i = h[x]; i; i = e[i].nxt)
#define str(s, l) cin >> (s); int (l) = (s).size()
#define crstr(s, l) string (s); cin >> (s); int (l) = (s).size()
#define crstrline(s, l) string (s); getline(cin, (s)); int (l) = (s).size()
#define ll long long //No long long see your ancestor!!!
#define ull unsigned long long //Have long long see your ancestor!!!
#define lll __int128 //Have unsigned long long see your ancestor!!!
#define ld long double
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define yes puts("yes")
#define no puts("no")
#define iv inline void
#define ii inline int
#define ill inline ll
#define iull inline ull
#define i128 inline lll
#define ib inline bool
#define iT inline T
#define ilf inline double
#define ild inline ld
#define istr inline string
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pq priority_queue
using namespace std;

namespace fastExpress {
    Tl iT read() {T f = 1, x = 0; char c = getchar(); while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();} while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();} return x * f;}
	Tl iv write(T x) {if(x < 0) {putchar('-'); x = -x;} if(x > 9) write(x / 10); putchar(x % 10 + '0');}
    Tl iv print_char(T x, char ch) {write(x), putchar(ch);}
    Tl iv char_print(char ch, T x) {putchar(ch); write(x);}
    Tl iv print_space(T x) {print_char(x, ' ');}
    Tl iv space_print(T x) {char_print(' ', x);}
    Tl iv println(T x) {print_char(x, '\n');}
    Tl iv lnprint(T x) {char_print('\n', x);}
    Tl iv print_array_in_range1(T *a, int l, int r) {F(int, i, l, r) print_char(a[i], " \n"[i == r]);}
    Tl iv print_array_in_range2(T* a, int l, int r) {println(r - l + 1), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range3(T* a, int l, int r) {R(int, i, r, l) print_char(a[i], " \n"[i == l]);}
    Tl iv print_array_in_range4(T* a, int l, int r) {println(r - l + 1), print_array_in_range3(a, l, r);}
    Tl iv print_array_in_range5(T *a, int l, int r) {F(int, i, l, r) println(a[i]);}
    Tl iv print_array_in_range6(T* a, int l, int r) {println(r - l + 1), print_array_in_range5(a, l, r);}
    Tl iv print_array_in_range7(T* a, int l, int r) {R(int, i, r, l) println(a[i]);}
    Tl iv print_array_in_range8(T* a, int l, int r) {println(r - l + 1), print_array_in_range7(a, l, r);}
    Tl iv print_array_in_range9(T* a, int l, int r) {print_space(r - l + 1), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range10(T* a, int l, int r) {print_space(r - l + 1), print_array_in_range3(a, l, r);}
    Tl iv print_array_in_range11(T* a, int l, int r) {print_space(r - l + 1), print_array_in_range5(a, l, r);}
    Tl iv print_array_in_range12(T* a, int l, int r) {print_space(r - l + 1), print_array_in_range7(a, l, r);}
    Tl iv print_array_in_range13(T* a, int l, int r, int n) {println(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range14(T* a, int l, int r, int n) {println(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range15(T* a, int l, int r, int n) {println(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range16(T* a, int l, int r, int n) {println(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range17(T* a, int l, int r, int n) {print_space(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range18(T* a, int l, int r, int n) {print_space(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range19(T* a, int l, int r, int n) {print_space(n), print_array_in_range1(a, l, r);}
    Tl iv print_array_in_range20(T* a, int l, int r, int n) {print_space(n), print_array_in_range1(a, l, r);}
    Tl iv print_array1(T *a, int n) {print_array_in_range1(a, 1, n);}
    Tl iv print_array2(T *a, int n) {println(n), print_array1(a, n);}
	Tl iv print_array3(T *a, int n) {print_array_in_range3(a, 1, n);}
	Tl iv print_array4(T* a, int n) {println(n), print_array3(a, n);}
    Tl iv print_array5(T* a, int n) {print_array_in_range5(a, 1, n);}
    Tl iv print_array6(T* a, int n) {println(n), print_array5(a, n);}
    Tl iv print_array7(T* a, int n) {print_array_in_range7(a, 1, n);}
    Tl iv print_array8(T* a, int n) {println(n), print_array7(a, n);}
    Tl iv print_array9(T *a, int n) {print_space(n), print_array1(a, n);}
	Tl iv print_array10(T *a, int n) {print_space(n), print_array3(a, n);}
    Tl iv print_array11(T* a, int n) {print_space(n), print_array5(a, n);}
    Tl iv print_array12(T* a, int n) {print_space(n), print_array7(a, n);}
    Tl iv vector_print(vector<T> a, int l, int r) {F(int, i, l, r) print_char(a[i], " \n"[i == r]);}
    Tl iv map_print(map<T, T> a, int l, int r) {F(int, i, l, r) print_char(a[i], " \n"[i == r]);}
    Tl iv stack_print(stack<T> a, char ch) {while(!a.empty()) print_char(a.top(), ch), a.pop();}
    Tl iv queue_print(queue<T> a, char ch) {while(!a.empty()) print_char(a.front(), ch), a.pop();}
    Tl iv pq_print(pq<T> a, char ch) {while(!a.empty()) print_char(a.top(), ch), a.pop();}
    iv print_string_in_range(string s, int l, int r) {F(int, i, l, r) putchar(s[i]);}
    iv print_chars_in_range(char* a, int l, int r) {F(int, i, l, r) putchar(a[i]);}
    iv print_allstring(string s) {print_string_in_range(s, 0, (int)s.size() - 1);}
    iv filein(string s) {freopen((s + ".in").c_str(), "r", stdin);}
    iv fileout(string s) {freopen((s + ".out").c_str(), "w", stdout);}
    iv file(string s) {filein(s), fileout(s);}
}
using namespace fastExpress;
#define Rint read<int>()
#define Rll read<ll>()
#define Rull read<ull>()
#define R128 read<lll>()
#define MT int Test = Rint; while(Test--)

const int N = 1e6 + 7;
string s, ans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int> val;
int len, p1 = -1, p2 = -1, fl, flag;

iv RXCYtoALPHA(string s) {
    int row = 0, col = 0;
    F(int, i, p1 + 1, p2 - 1) row = row * 10 + s[i] - '0';
    F(int, i, p2 + 1, len - 1) col = col * 10 + s[i] - '0';
    int p = col; string newcol = "";
    while(p) newcol += ans[(!(p % 26) ? 26 : p % 26) - 1], p = p / 26 - !(p % 26);
    reverse(newcol.begin(), newcol.end());
    cout << newcol << row << endl;
    return;
}
iv ALPHAtoRXCY(string s) {
    int row = 0, col = 0, cur = 0;
    while(isupper(s[cur])) col = col * 26 + val[s[cur]], cur++;
    for(; cur < len; ++cur) row = row * 10 + s[cur] - '0';
    printf("R%dC%d\n", row, col);
}

int main() {
    MT {
        F(int, i, 0, 25) val[ans[i]] = i + 1;
        cin >> s, len = s.size(), p1 = -1, p2 = -1, fl = 1, flag = 1;
        F(int, i, 0, len - 1) {
            if(s[i] == 'R') p1 = i; else if(s[i] == 'C') p2 = i;
            if(!isupper(s[i])) fl = 0;
            if(!fl && isupper(s[i])) flag = 0;
        }
        if(!flag) RXCYtoALPHA(s);
        else ALPHAtoRXCY(s);
    }
    return 0;
}
/*

*/