#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define all(a) a.begin(), a.end()
#define mp make_pair

void solve();

int main(){
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	while (t--)
		solve();
	return 0;
}

struct TElem{
	int data;
	TElem *next;
	TElem(int Data){ next = 0; data = Data; }
};

struct List{
	TElem *root;
	List(){ root = 0; }
	void add (int data, int after){
		if (root == 0){
			root = new TElem(data);
			return;
		}
		TElem *now = root;
		while (now != 0){
			if (now->data == after){
				add(now, data);
				return;
			}
			if (now->next == 0){
				add(now, data);
				return;
			}
			now = now->next;
		}
	}
	void add(TElem *&cur, int data){
		TElem *nex = new TElem(data);
		nex->next = cur->next;
		cur->next = nex;
	}
	void remove(int data){
		TElem *cur = root;
		while (root != 0 && root->data == data){
			root = root->next;
		}
		while (cur != 0){
			if (cur->next == 0)
				break;
			if (cur->next->data == data){
				TElem *now = cur->next->next;
				delete cur->next;
				cur->next = now;
			}
			cur = cur->next;
		}
		cout<<endl;
	}
	void print(){
		TElem *cur = root;
		while (cur != 0){
			cout<<cur->data<<' ';
			cur = cur->next;
		}
		cout<<endl;
	}
};
#define int long long
void solve(){

	int n;
	cin>>n;

	if (n == 1){
		cout<<1;
		return;
	}
	if (n == 2){
		cout<<2;
		return;
	}
	if (n == 3){
		cout<<6;
		return;
	}

	int ans = n * (n - 1) * (n - 2);
	if (n % 2){
		cout<<ans;
		return;
	}
	ans /= 2;
	ans = max(ans, (n - 1) * (n - 2) * (n - 3));
	if (n % 3)
		ans = max(ans, n * (n - 1) * (n - 3));

	cout<<ans;

	/*List l;
	int n = 15;

	for (int i = 0; i < n; ++i){
		int cur, after;
		string s;
		cin>>s;
		cin>>cur;
		if (s[0] == 'a'){
			cin>>after;
			l.add(cur, after);
		}
		else
			l.remove(cur);
		//l.add(rand() % 10, rand() % 10);
		l.print();
	}*/

}