def main():
    s = [ord(i) - ord('a') for i in input()]
    k = int(input())
    w = [int(i) for i in input().split()]
    
    s = [w[i] for i in s] + [max(w) for i in range(k)]
    
    result = 0
    for i in range(len(s)):
        result += s[i] * (i + 1)
    
    print(result)


main()