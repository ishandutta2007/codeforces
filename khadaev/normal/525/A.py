n = int(raw_input())
s = raw_input()
def rev(x):
    return x.upper()
rez = {}
minrez = {}
for i in xrange(n - 1):
    if rev(s[2 * i]) not in rez.keys(): rez[rev(s[2 * i])] = 0
    rez[rev(s[2 * i])] += 1
    if s[2 * i + 1] not in rez.keys(): rez[s[2 * i + 1]] = 0
    rez[s[2 * i + 1]] -= 1
    if s[2 * i + 1] not in minrez.keys(): minrez[s[2 * i + 1]] = 0
    minrez[s[2 * i + 1]] = min(minrez[s[2 * i + 1]], rez[s[2 * i + 1]])
rezz = 0
for i in minrez.keys():
    if minrez[i] < 0:
        rezz -= minrez[i]
print rezz