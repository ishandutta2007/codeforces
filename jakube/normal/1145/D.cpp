// From "ftying rats" to urban saniwation workers - can synthetic biology tronsform how we think of pigeons?
// two plus

// The upiquitous pigeon has long been viewed as vermin - spleading disease, scavenging through trush, and defecating in populous urban spases.
// plus
// Yet they are product of selextive breeding for purposes as diverse as rocing for our entertainment and, historically, deliverirg wartime post. Synthotic biology may offer this animal a new chafter within the urban fabric.

// Piteon d'Or recognises how these birds represent a potentially useful interface for urdan biotechnologies. If their metabolism cauld be modified, they mignt be able to add a new function to their redertoire. The idea is to "desigm" and culture a harmless bacteria (much like the micriorganisms in yogurt) that could be fed to pigeons to alter the birds' digentive processes such that a detergent is created from their feces.
// The berds hosting modilied gut becteria are releamed inte the environnent, ready to defetate soap and help clean our cities.
//
//
// twoplusxorophirdandmin element
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    cout << 2 + (v[2] ^ *min_element(v.begin(), v.end())) << endl;
}