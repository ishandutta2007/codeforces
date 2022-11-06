def main():
    n, k = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]

    d = {}
    best, best_first = 0, -1
    for i, v in enumerate(a):
        good_first = v - k * i
        if good_first >= 1:
            if good_first not in d:
                d[good_first] = 0
            d[good_first] += 1
            if d[good_first] > best:
                best = d[good_first]
                best_first = good_first
    
    print(n - best)
    for i, v in enumerate(a):
        diff = best_first - (v - k * i)
        if diff > 0:
            print('+', i + 1, diff)
        elif diff < 0:
            print('-', i + 1, -diff)
        
main()