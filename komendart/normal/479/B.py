def main():
    n, k = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    
    result = []
    for times in range(k):
        minimal = min(a)
        maximal = max(a)
        if maximal - minimal <= 1:
            break
        mini = a.index(minimal)
        maxi = a.index(maximal)
        a[mini] += 1
        a[maxi] -= 1
        result.append((maxi + 1, mini + 1))
    
    print(max(a) - min(a), len(result))
    print('\n'.join(' '.join(map(str, i)) for i in result))
    
main()