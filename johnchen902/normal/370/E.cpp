#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

const int max_n    = 200000;
const int max_book = 100000;

int n, a[max_n];
std::vector<std::pair<int, int> > requirement; // (day, book)

int psb_left[max_book + 1], psb_right[max_book + 1];

int solve() {
    for(size_t i = 1; i < requirement.size(); i++)
        if(requirement[i - 1].second > requirement[i].second)
            return -1;

    psb_left[0] = psb_right[0] = -1;
    int book = 1;

    for(size_t rq = 0; rq < requirement.size(); book++) {
        psb_left[book] = psb_left[book - 1] + 2;
        psb_right[book] = psb_right[book - 1] + 5;
        while(requirement[rq].second == book) {
            if(psb_right[book] < requirement[rq].first || psb_left[book - 1] >= requirement[rq].first)
                return -1;
            psb_left[book] = std::max(psb_left[book], requirement[rq].first);
            psb_right[book] = std::min(psb_right[book], requirement[rq].first + 4);
            if((++rq) == requirement.size())
                break;
        }
    }
    book--;
    int read_book = -1, chosen = n;
    if(psb_left[book] >= n) {
        return -1;
    } else if(psb_left[book] == n - 1) {
        read_book = book;
        chosen = n - 1;
    } else if(psb_left[book] == n - 2) {
        if(psb_right[book] < n - 1)
            return -1;
        read_book = book;
        chosen = n - 1;
    } else {
        read_book = book + (n - 1 - psb_left[book]) / 2;
        for(int x = psb_left[book] + 1; x < n; x++)
            a[x] = book + (x - psb_left[book] + 1) / 2;
        if(a[n-1] != a[n-2])
            a[n-1] = a[n-2];
        chosen = psb_left[book];
    }
    for(; book > 0; book--){
        // choose between (psb_left[book-1] + 1, psb_right[book-1] + 1)
        // and between (chosen - 4, chosen - 1)
        int chosen_next = std::max(psb_left[book-1] + 1, chosen - 4);

        std::fill(a + chosen_next, a + chosen + 1, book);
        chosen = chosen_next - 1;
    }
    return read_book;
}

int main() {
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] != 0) {
            requirement.push_back(std::make_pair(i, a[i]));
        }
    }
    int answer = solve();
    std::cout << answer << std::endl;
    if(answer != -1) {
        std::cout << a[0];
        for(int i = 1; i < n; i++)
            std::cout << " " << a[i];
        std::cout << std::endl;
    }
}