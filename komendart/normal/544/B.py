def main():
    n, k = [int(i) for i in input().split()]
    result = [['S' for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(i % 2, n, 2):
            if k > 0:
                result[i][j] = 'L'
                k -= 1
    
    if k > 0:
        print("NO")
    else:
        print("YES")
        print('\n'.join(''.join(j for j in i) for i in result))
    

main()