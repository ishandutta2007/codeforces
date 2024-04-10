from collections import *
def get_score(word, k):
    if len(set(word)) == k == 1: return max(1, len(word) - 1)
    return min(len(word), max(Counter(word).values()) + k)

k = input()
names = ['Kuro', 'Shiro', 'Katie']
scores = [get_score(raw_input(), k) for i in xrange(3)]
maxscore = max(scores)
gots = [i for i in xrange(3) if scores[i] == maxscore]
if len(gots) == 1:
    [i] = gots
    print names[i]
else:
    print 'Draw'