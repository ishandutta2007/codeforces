#include <bits/stdc++.h>
#include <windows.h>

#define f first
#define s second
#define ll long long
#define ld long double
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

using namespace std;

const int inf = 2e9;
const double eps = 1e-9;
const int maxn = 1e6 + 5, base = 1e9+7;

void bad(string mes = "NO"){cout << mes;exit(0);}

template<typename T>
string bin(T x){
	string ans = "";
	while (x > 0){
		ans += char('0' + x % 2);
		x /= 2;
	}
	reverse(ans.begin(), ans.end());
	return ans.empty() ? "0" : ans;
}

template<typename T = int >
T input(){
	T ans = 0, m = 1;
	char c = ' ';
	while (c == ' ' || c == '\n')
		c = getchar();
	if (c == '-')
		m = -1,	c = getchar();
	while (c != ' ' && c != '\n')
		ans = ans * 10 + c - '0', c = getchar();
	return ans * m;
}

template<typename T>
T sqr(T x)
{
	return x * x;
}
#define plus joiagsd
int inst[maxn];
bool plus[maxn];

int main()
{
	int n = 0, sum = 0;
	int a = 1, b = 0;

    plus[0] = 1;

	for (int i = 1; ;){
		string s;
		cin >> s;
		if (s == "+"){
			a++;
			plus[i] = 1;
			i++;
			continue;
		}
		if (s == "-"){
			b++;
			i++;
			continue;
		}

		stringstream to;
		if (s == "?"){
			n++;
			continue;
		}

		cin >> s;
		to << s;
		to >> sum;
		break;
	}

	if (a - b * sum <= sum && sum <= a * sum - b){
		puts("Possible");
		for (int i = 0; i < n; i++)
			inst[i] = 1;
		int cursum = a - b;
		for (int i = 0; i < n; i++){
			if (plus[i] && cursum < sum){
				inst[i] = min(sum - cursum + 1, sum);
				cursum = cursum - 1 + inst[i];
			}
			if (!plus[i] && cursum > sum){
				inst[i] = min(cursum + 1 - sum, sum);
				cursum = cursum + 1 - inst[i];
			}
		}

		for (int i = 0; i < n; i++){
            if (i != 0){
                if (plus[i])
                    printf("+ ");
                else
                    printf("- ");
            }
			printf("%d ", inst[i]);
		}
		printf("= %d\n", sum);
	} else bad("Impossible");
}