def main():
    s = input()
    k = int(input())
    
    s += '?' * k
    
    N = len(s)
    
    result = 0
    
    for l in range(1, N):
        count = 0
        for i in range(N - l):
            if s[i] == s[i + l] or s[i + l] == '?':
                count += 1
                if count == l:
                    result = l
                    break
            else:
                count = 0
    
    print(result * 2)
                    

main()