NUM = int(input())
for T in range(0,NUM):
    n , k = map(int , input().split())
    vallist = list(map(int , input().split()))
    answer = [0] * n
    countnum = [[] for i in range(0,n)]
    for i in range(0,n): countnum[vallist[i] - 1].append(i)
    ans = 0
    for i in range(0,n): ans += min(k , len(countnum[i]))
    ans //= k
    current = 0
    for i in countnum:
        for j in range(0 , min(k , len(i))):
            if ans:
                answer[i[j]] = current + 1
                current = (current + 1) % k
                ans -= current == 0
    for i in answer: print(i, end = " ")
    print("")