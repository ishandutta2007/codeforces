def main():
    n = int(input())
    s = input()
    
    result = 0
    d = [0 for i in range(256)]
    for i in range(n - 1):
        key = s[i * 2]
        door = ord(s[i * 2 + 1])
        if key.islower(): key = key.upper()
        else: key = key.lower()
        d[ord(key)] += 1
        if not d[door]:
            result += 1
        else:
            d[door] -= 1
    
    print(result)
    
    
main()