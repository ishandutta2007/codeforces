def main():
    from collections import defaultdict
    
    m, k = [int(i) for i in input().split()]
    
    d = defaultdict(set)
    for i in range(m):
        a, b = [int(i) for i in input().split()]
        d[a].add(b)
        d[b].add(a)
    
    keys = sorted(d.keys())
    for i in keys:
        result = []
        for j in keys:
            if j not in d[i] and i != j and len(d[i] & d[j]) * 100 >= len(d[i]) * k:
                result.append(j)
        print("{0}: {1} {2}".format(i, len(result), ' '.join(str(i) for i in result)))
            
    
main()