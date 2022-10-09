#include "bits/stdc++.h"
using namespace std;

// Template magic!
template<class T, int order>
struct PersistentArray {
 
    typedef PersistentArray<T, order - 1> lower_t;
    typedef PersistentArray<T, order> this_t;
 
    lower_t* left;
    lower_t* right;
 
    T operator[] (int n) {
        if (n < (1 << (order - 1))) {
            return (*left)[n];
        } else {
            return (*right)[n - (1 << (order - 1))];
        }
    }
 
    PersistentArray<T, order>() :
        left(new lower_t),
        right(new lower_t) {}
 
    this_t* getCopy(int idx, T newVal) {
        this_t* tmp = new this_t(*this);
        if (idx < (1 << (order - 1))) {
            tmp->left = left->getCopy(idx, newVal);
        } else {
            tmp->right = right->getCopy(idx - (1 << (order - 1)), newVal);
        }
        return tmp;
    }
};

template<class T>
struct nula {};

template<>
struct nula<int> {
	static constexpr int value = 0;
};

template<class T>
struct nula<T*> {
	static constexpr T* value = nullptr;
};
 
template<class T>
struct PersistentArray<T, 0> {
    T data;
 
    typedef PersistentArray<T, 0> this_t;
 
    T operator[] (int) {
        return data;
    }
 
    PersistentArray() : data(nula<T>::value) {}
 
    this_t* getCopy(int, T newVal) {
        this_t* tmp = new this_t;
        tmp->data = newVal;
        return tmp;
    }
};

struct MyPersistentRow {
	int inv;
	int len;
	int cnt;
	PersistentArray<int, 10>* arr;
	
	MyPersistentRow(int len) : inv(0), len(len), cnt(0), arr(new PersistentArray<int, 10>) {}
	
	int operator[] (int x) {
        return inv ^ (*arr)[x];
    }
	
	MyPersistentRow* getFlip(){
		auto p = new MyPersistentRow(*this);
		p->inv = 1 ^ inv;
		p->cnt = len - cnt;
		return p;
	}
	
	MyPersistentRow* getCopy(int pos, int newVal){
		auto p = new MyPersistentRow(*this);
		int old = inv ^ (*arr)[pos];
		
		p->arr = arr->getCopy(pos, newVal ^ inv);
		p->cnt = cnt + newVal - old;
		return p;
	}
};

struct Matrix {
	PersistentArray<MyPersistentRow*, 10>* mx;
	int total;
	
	Matrix (int N, int M){
		total = 0;
		mx = new PersistentArray<MyPersistentRow*, 10>;
		for (int i=1; i<=N; i++){
			mx = mx->getCopy(i, new MyPersistentRow(M));
		}
	}
	
	Matrix(int total, PersistentArray<MyPersistentRow*, 10>* mx) : mx(mx), total(total) {}
	
	Matrix* set(int i, int j, int val){
		int old = (*(*mx)[i])[j];
		//cerr << "@" << old << endl;
		return new Matrix(total + val - old, mx->getCopy(i, (*mx)[i]->getCopy(j, val)));
	}
	
	Matrix* flip(int i){
		int old = (*mx)[i]->cnt;
		int nu = (*mx)[i]->len - old;
		//cerr << "!" << total << ' ' << old << ' ' << nu << endl;
		return new Matrix(total + nu - old, mx->getCopy(i, (*mx)[i]->getFlip()));
	}
};

Matrix* states[100005];

int main(){
	int N, M, Q, K=0;
	cin >> N >> M >> Q;
	states[0] = new Matrix(N, M);
	
	while (Q--){
		int t, i, j, k;
		cin >> t;
		if (t==1){
			cin >> i >> j;
			states[K+1] = states[K]->set(i, j, 1);
		} else if (t==2){
			cin >> i >> j;
			states[K+1] = states[K]->set(i, j, 0);
		} else if (t==3){
			cin >> i;
			states[K+1] = states[K]->flip(i);
		} else {
			cin >> k;
			states[K+1] = states[k];
		}
		cout << states[K+1]->total << endl;
		K++;
	}
	return 0;
}