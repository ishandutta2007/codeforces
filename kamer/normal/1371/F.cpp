#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<char> vc;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    bool flipBelow = false;
    char c = ' ';
    int mG = 0, mFG = 0;
    int mLL = 0, mLR = 0, mRL = 0, mRR = 0, mLLR = 0, mLRL = 0, mRLR = 0, mRRL = 0;
    Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of in f
    Node(string& s, int lo, int hi) : lo(lo), hi(hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo)/2;
            l = new Node(s, lo, mid); r = new Node(s, mid, hi);
        }
        else {
            c = s[lo];
        }
        fillMetadata();
         
    }

    int size() {
        return hi - lo;
    }

    int size(int L, int R) {
        if (R <= lo || L >= hi) return 0;
        if (L >= lo && R <= hi) return R - L;
        if (L < lo) {
            return min(R, hi) - lo;
        }
        if (R > hi) {
            return hi - max(L, lo);
        }
    }

    void fillMetadata() {
        if (size() == 1) {
            if (c == '<') {
                mLL = 1, mRL = 1, mLLR = 1, mRLR = 1;
            } else {
                mLR = 1, mRR = 1, mLRL = 1, mRRL = 1;       
            }
            mG = 1, mFG = 1;
        } else {
            if (r->mRR == r->size()) {
                mRR = r->mRR + l->mRR;
            } else {
                mRR = r->mRR;
            }

            if (r->mRL == r->size()) {
                mRL = r->mRL + l->mRL;
            } else {
                mRL = r->mRL;
            }

            if (l->mLR == l->size()) {
                mLR = l->mLR + r->mLR;
            } else {
                mLR = l->mLR;
            }

            if (l->mLL == l->size()) {
                mLL = l->mLL + r->mLL;
            } else {
                mLL = l->mLL;
            }

            if (r->mRRL == r->size()) {
                if (r->mRR == r->size()) {
                    mRRL = r->mRR + max(l->mRRL, l->mRL);
                } else {
                    mRRL = r->mRRL + l->mRL;
                }
            } else {
                mRRL = r->mRRL;
            }

            if (r->mRLR == r->size()) {
                if (r->mRL == r->size()) {
                    mRLR = r->mRL + max(l->mRLR, l->mRR);
                } else {
                    mRLR = r->mRLR + l->mRR;
                }
            } else {
                mRLR = r->mRLR;
            }

            if (l->mLRL == l->size()) {
                if (l->mLR == l->size()) {
                    mLRL = l->mLR + max(r->mLRL, r->mLL);
                } else {
                    mLRL = l->mLRL + r->mLL;
                }
            } else {
                mLRL = l->mLRL;
            }

            if (l->mLLR == l->size()) {
                if (l->mLL == l->size()) {
                    mLLR = l->mLL + max(r->mLLR, r->mLR);
                } else {
                    mLLR = l->mLLR + r->mLR;
                }
            } else {
                mLLR = l->mLLR;
            }

            mG = max(l->mG, r->mG);
            mG = max(mG, mLRL);
            mG = max(mG, mRLR);
            mG = max(mG, mLL);
            mG = max(mG, mRR);
            mG = max(mG, l->mRLR + r->mLL);
            mG = max(mG, l->mRR + r->mLRL);
            mG = max(mG, l->mRR + r->mLL);


            mFG = max(l->mFG, r->mFG);
            mFG = max(mFG, mLLR);
            mFG = max(mFG, mRRL);
            mFG = max(mFG, mLR);
            mFG = max(mFG, mRL);
            mFG = max(mFG, l->mRRL + r->mLR);
            mFG = max(mFG, l->mRL + r->mLLR);
            mFG = max(mFG, l->mRL + r->mLR);
        }
    }

    tuple<int, int, int, int, int, int, int, int, int> query(int L, int R) {
        
        //cout << "meta " << lo << " " << hi << " " << mLL << " " << mLR << " " << mRL << " " << mRR
        //     << " " << mLLR << " " << mLRL << " " << mRLR << " " << mRRL << " " << mG << "\n";
        if (R <= lo || hi <= L) return make_tuple(-1, -1, -1, -1, -1, -1, -1, -1, -1);
        if (L <= lo && hi <= R) return make_tuple(mG, mLL, mLR, mRL, mRR, mLLR, mLRL, mRLR, mRRL);
        push();
        auto lT = l->query(L, R);
        auto rT = r->query(L, R);
        if (get<0>(lT) == -1) return rT;
        if (get<0>(rT) == -1) return lT;

        int lmG = get<0>(lT), lmLL = get<1>(lT), lmLR = get<2>(lT), lmRL = get<3>(lT),
            lmRR = get<4>(lT), lmLLR = get<5>(lT), lmLRL = get<6>(lT), lmRLR = get<7>(lT),
            lmRRL = get<8>(lT);
    
        int rmG = get<0>(rT), rmLL = get<1>(rT), rmLR = get<2>(rT), rmRL = get<3>(rT),
            rmRR = get<4>(rT), rmLLR = get<5>(rT), rmLRL = get<6>(rT), rmRLR = get<7>(rT),
            rmRRL = get<8>(rT);

        int cmG, cmLL, cmLR, cmRL, cmRR, cmLLR, cmLRL, cmRLR, cmRRL;
        if (rmRR == r->size(L, R)) {
            cmRR = rmRR + lmRR;
        } else {
            cmRR = rmRR;
        }

        if (rmRL == r->size(L, R)) {
            cmRL = rmRL + lmRL;
        } else {
            cmRL = rmRL;
        }

        if (lmLR == l->size(L, R)) {
            cmLR = lmLR + rmLR;
        } else {
            cmLR = lmLR;
        }

        if (lmLL == l->size(L, R)) {
            cmLL = lmLL + rmLL;
        } else {
            cmLL = lmLL;
        }

        if (rmRRL == r->size(L, R)) {
            if (rmRR == r->size(L, R)) {
                cmRRL = rmRR + max(lmRRL, lmRL);
            } else {
                cmRRL = rmRRL + lmRL;
            }
        } else {
            cmRRL = rmRRL;
        }

        if (rmRLR == r->size(L, R)) {
            if (rmRL == r->size(L, R)) {
                cmRLR = rmRL + max(lmRLR, lmRR);
            } else {
                cmRLR = rmRLR + lmRR;
            }
        } else {
            cmRLR = rmRLR;
        }

        if (lmLRL == l->size(L, R)) {
            if (lmLR == l->size(L, R)) {
                cmLRL = lmLR + max(rmLRL, rmLL);
            } else {
                cmLRL = lmLRL + rmLL;
            }
        } else {
            cmLRL = lmLRL;
        }

        if (lmLLR == l->size(L, R)) {
            if (lmLL == l->size(L, R)) {
                cmLLR = lmLL + max(rmLLR, rmLR);
            } else {
                cmLLR = lmLLR + rmLR;
            }
        } else {
            cmLLR = lmLLR;
        }

        cmG = max(lmG, rmG);
        cmG = max(cmG, cmLRL);
        cmG = max(cmG, cmRLR);
        cmG = max(cmG, cmLL);
        cmG = max(cmG, cmRR);
        cmG = max(cmG, lmRLR + rmLL);
        cmG = max(cmG, lmRR + rmLRL);
        cmG = max(cmG, lmRR + rmLL);

        return make_tuple(cmG, cmLL, cmLR, cmRL, cmRR, cmLLR, cmLRL, cmRLR, cmRRL);
    }

    void flip(int L, int R) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) {
            flipMetadata();
        } else {
            push();
            l->flip(L, R);
            r->flip(L, R);
            fillMetadata();
        }
    }

    void flipMetadata() {
        flipBelow = !flipBelow;
        swap(mLL, mLR);
        swap(mRL, mRR);
        swap(mLLR, mLRL);
        swap(mRLR, mRRL);
        swap(mG, mFG);
        if (c == '<') c = '>';
        else if (c == '>') c = '<';
    }

    void push() {
        if (flipBelow) {
            l->flip(lo, hi);
            r->flip(lo, hi);
            flipBelow = false;
            fillMetadata();
        }
    }

    char findChar(int i) {
        if (lo + 1 == hi) {
            if (lo == i) {
                return c;
            } else {
                return ' ';
            }
        }
        push();
        char c1 = l->findChar(i);
        char c2 = r->findChar(i);
        if (c1 == ' ') return c2;
        return c1;
    }

    void printMetadata() {
        cout << "meta " << lo << " " << hi << " " << mLL << " " << mLR << " " << mRL << " " << mRR
             << " " << mLLR << " " << mLRL << " " << mRLR << " " << mRRL << " " << mG << "\n";
        if (l) {
            push();
            l->printMetadata();
            r->printMetadata();
        }
    }
};

int main(void) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    Node* v = new Node(s, 0, n);
    
    //for (int i = 0; i < n; i++) {
    //    cout << v->findChar(i);
    //}
    //cout << "\n";
    //v->printMetadata();
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        v->flip(l - 1, r);
        
        //if (i == 1) {
        auto res = v->query(l - 1, r);
        cout << get<0>(res) << "\n";
        //}

        //for (int i = 0; i < n; i++) {
        //    cout << v->findChar(i);
        //}
        //cout << "\n";
        //v->printMetadata();
    }
}