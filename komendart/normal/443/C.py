from itertools import combinations
from copy import copy

def variants(a):
    for i in range(6):
        for j in combinations(a, i):
            yield j

def main():
    input()
        
    cards = set((i[0], int(i[1])) for i in input().split())
    
    values = [0 for i in range(6)]
    masks = {i: 0 for i in "RGBYW"}
    
    for i in cards:
        values[i[1]] += 1
        masks[i[0]] += 1

    result = float("inf")
    
    for i in variants("RGBYW"):
        for j in variants(list(range(1, 6))):
            c = copy(cards)
            v, m = values[:], copy(masks)
            for k in copy(c):
                if k[0] in i and k[1] in j:
                    v[k[1]] -= 1
                    m[k[0]] -= 1
                    c.remove(k)
            for l in range(11):
                for k in copy(c):
                    if (v[k[1]] == 1 and k[1] in j or
                    m[k[0]] == 1 and k[0] in i):
                        v[k[1]] -= 1
                        m[k[0]] -= 1
                        c.remove(k)
            if len(c) <= 1:
                result = min(result, len(i) + len(j))
    
    print(result)

main()