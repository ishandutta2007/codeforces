#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";

int t, n;
string X = "What are you doing while sending ";
string Y = "? Are you busy? Will you send ";
string Z;
const int N = 100005;
long long sizes[100005];
int lenX, lenY, lenZ;
// fn = X + fn-1 + Y + fn-1 + Z
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
char get(int n, long long k){
	if(sizes[n] < k) return '.';
	if(n == 0) return f0[k - 1];
	if(k <= X.length()) return X[k - 1];
	if(k <= X.length() + sizes[n - 1]) return get(n - 1, k - X.length());
	if(k <= X.length() + sizes[n - 1] + Y.length()) return Y[k - X.length() - sizes[n - 1] - 1];
	if(k <= X.length() + sizes[n - 1] + Y.length() + sizes[n - 1]) return get(n - 1, k - (X.length() + sizes[n - 1] + Y.length()));
	return Z[k - (X.length() + sizes[n - 1] + Y.length() + sizes[n - 1]) - 1];
}
const ll MAX = 2e18;
int main(){
	char annot = 34;
	string Annot;
	Annot.append(1, annot);
	X = X + Annot;
	Y = Annot + Y + Annot;
	Z = Annot + "?";
	sizes[0] = f0.length();
	lenX = X.length(), lenY = Y.length(), lenZ = Z.length();
	for(int i = 1; i < N; i++) sizes[i] = min(MAX, (2 * sizes[i - 1] + lenX + lenY + lenZ));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		cout << get(n, k);
	}
}