def main():
    n = int(input())
    result = []
    for i in range(2, n + 1):
        j = 2
        while j * j <= i:
            if i % j == 0:
                break
            j += 1
        else:
            j = i
            while j <= n:
                result.append(j)
                j *= i
    
    print(len(result))
    print(' '.join(str(i) for i in result))
    
    
    
main()