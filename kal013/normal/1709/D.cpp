/*/ Author: kal013 /*/
// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

template<class T> 
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T> >; 

/*/---------------------------IO(Debugging)----------------------/*/

template<typename T_container, typename T = typename std::enable_if<!std::is_same<T_container, std::string>::value, typename T_container::value_type>::type> 
std::istream& operator >> (std::istream &is, T_container &v) { 
   for(T &x : v) {is >> x;} return is;
}
#ifdef __SIZEOF_INT128__
std::ostream& operator << (std::ostream &os, __int128 const& value){
    static char buffer[64];
    int index = 0;
    __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
    if (value < 0) 
        os << '-';
    else if (T == 0)
        return os << '0';
    for(; T > 0; ++index){
        buffer[index] = static_cast<char>('0' + (T % 10));
        T /= 10;
    }    
    while(index > 0)
        os << buffer[--index];
    return os;
}
std::istream& operator >> (std::istream& is, __int128& T){
    static char buffer[64];
    is >> buffer;
    size_t len = strlen(buffer), index = 0;
    T = 0; int mul = 1;
    if (buffer[index] == '-')
        ++index, mul *= -1;
    for(; index < len; ++index)
        T = T * 10 + static_cast<int>(buffer[index] - '0');
    T *= mul;    
    return is;
}
#endif

#ifdef __LOCAL_KAL013__
    #include "debug.h"
#else
    #define trace(...) 1
#endif

/*/---------------------------RNG----------------------/*/
inline int64_t random_long(int64_t l = LLONG_MIN, int64_t r = LLONG_MAX){
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int64_t> generator(l,r);
    return generator(rng);
}
struct custom_hash { // Credits: https://codeforces.com/blog/entry/62393
    static uint64_t splitmix64(uint64_t x) { // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(std::pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
    }
};

namespace FastIO{ // Adapted from nor (https://github.com/NavneelSinghal/CodeBook/blob/master/misc/io.cpp) and yosupo 
	namespace Internal {
		template<typename T>
		struct internal_get_unsigned{
			typedef typename make_unsigned<T>::type type;
		};
		#ifdef __SIZEOF_INT128__
			template<> struct internal_get_unsigned<__int128>{ 
				typedef __uint128_t type; 
			};
			template<> struct internal_get_unsigned<__uint128_t>{ 
				typedef __uint128_t type; 
			};
		#endif

		template <class T>
		struct is_int {
			static constexpr bool value = std::is_integral<T>::value;
		};
		#ifdef __SIZEOF_INT128__
			template <> struct is_int<__int128_t> { static constexpr bool value = true; };
			template <> struct is_int<__uint128_t> { static constexpr bool value = true; };
		#endif


		template <class T>
		struct is_char {
		    static constexpr bool value = std::is_same<T, char>::value;
		};

		template <class T>
		struct is_bool {
		    static constexpr bool value = std::is_same<T, bool>::value;
		};

		template <class T>
		struct is_string {
		    static constexpr bool value =
		        std::is_same<T, std::string>::value || std::is_same<T, const char*>::value ||
		        std::is_same<T, char*>::value || std::is_same<std::decay_t<T>, char*>::value;
		    ;
		};

		template <class T, class D = void>
		struct is_custom {
		    static constexpr bool value = false;
		};

		template <class T>
		struct is_custom<T, std::void_t<typename T::internal_value_type>> {
		    static constexpr bool value = true;
		};

		template <class T>
		struct is_default {
		    static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
		                                  is_string<T>::value ||
		                                  is_int<T>::value;
		};

		template <class T, class D = void>
		struct is_iterable {
		    static constexpr bool value = false;
		};

		template <class T>
		struct is_iterable<
		    T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
		    static constexpr bool value = true;
		};

		template <class T, class D = void, class E = void>
		struct is_applyable {
		    static constexpr bool value = false;
		};

		template <class T>
		struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
		                    std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
		    static constexpr bool value = true;
		};
	};

	struct IOPre {
	    static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
	    std::array<char, 4 * SZ> num;
	    constexpr IOPre() : num{} {
	        for (int i = 0; i < SZ; i++) {
	            int n = i;
	            for (int j = 3; j >= 0; j--) {
	                num[i * 4 + j] = static_cast<char>(n % TEN + '0');
	                n /= TEN;
	            }
	        }
	    }
	};

	template<const bool SAFETY_CHECKS>
	struct IO {


		#if !HAVE_DECL_FREAD_UNLOCKED
			#define fread_unlocked fread
		#endif
		#if !HAVE_DECL_FWRITE_UNLOCKED
			#define fwrite_unlocked fwrite
		#endif
		
		static constexpr int BUFFER_SIZE = 1 << 17, LEN = 64, TEN = 10, HUNDRED = TEN * TEN,
	                         THOUSAND = HUNDRED * TEN, TENTHOUSAND = THOUSAND * TEN,
	                         MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
	                         TWELVE = 32, SIXTEEN = 36, INTEGER_WIDTH = 64;
	    static constexpr IOPre io_pre = {};


	    std::array<char, BUFFER_SIZE> input_buffer, output_buffer;
	    int input_start_ptr, input_end_ptr, output_end_ptr;
	    bool end_of_file;

	    FILE *read_fptr, *write_fptr;

		IO(FILE* read_fp, FILE* write_fp): read_fptr(read_fp), write_fptr(write_fp), input_buffer{}, output_buffer{}, input_start_ptr{}, input_end_ptr{}, output_end_ptr{}, end_of_file(false) {}
		IO(const IO&) = delete;
		IO(IO&&) = delete;
		IO& operator = (const IO&) = delete;
		IO& operator = (const IO&&) = delete;

		~IO() {flush();}

		template <class T>
	    static constexpr bool needs_newline = (Internal::is_iterable<T>::value ||
	                                           Internal::is_applyable<T>::value) &&
	                                          (!Internal::is_default<T>::value);

	    template <typename T, typename U>
	    struct any_needs_newline {
	        static constexpr bool value = false;
	    };
	    template <typename T>
	    struct any_needs_newline<T, std::index_sequence<>> {
	        static constexpr bool value = false;
	    };
	    template <typename T, std::size_t I, std::size_t... Is>
	    struct any_needs_newline<T, std::index_sequence<I, Is...>> {
	        static constexpr bool value =
	            needs_newline<decltype(std::get<I>(std::declval<T>()))> ||
	            any_needs_newline<T, std::index_sequence<Is...>>::value;
	    };


	    inline bool reload() { // Reloads without already read checks -- add read check for eof in interactive problems?.
	    	if constexpr (SAFETY_CHECKS) {
				assert (input_end_ptr >= input_start_ptr);
			}


	    	if (input_start_ptr > (BUFFER_SIZE >> 1)) [[unlikely]] {
	    		memmove(std::begin(input_buffer), std::begin(input_buffer) + input_start_ptr, input_end_ptr - input_start_ptr);
	    		input_end_ptr -= input_start_ptr;
	    		input_start_ptr = 0;
	    	}
	    	
	    	if (end_of_file) [[unlikely]]
	    		return false;
			else if (input_end_ptr == BUFFER_SIZE) [[unlikely]]
				return true;

	    	size_t read_length = fread_unlocked(std::begin(input_buffer) + input_end_ptr, sizeof(char), BUFFER_SIZE - input_end_ptr, read_fptr);

	    	if (read_length == 0) {
	    		end_of_file = true;
	    		input_buffer[input_end_ptr] = '\0';
	    		read_length = 1;
	    	}
	    	input_end_ptr += read_length;
	  		return true;
	    }

	    inline bool read_char(char& c) {
	    	if (input_start_ptr == input_end_ptr) [[unlikely]]{
	    		if (!reload())
	    			return false;
	    	}
			c = input_buffer[input_start_ptr++];    	
			return true;
	    }

	    inline bool read_string(std::string& s) {
	    	while (true) {
	    		while (input_start_ptr < input_end_ptr && input_buffer[input_start_ptr] <= ' ') ++input_start_ptr;
	    		if (input_start_ptr < input_end_ptr)
	    			break;
	    		if (!reload())
	    			return false;
	    	}
	    	s.clear();
	    	char x;
	    	while (true) {
	    		if (!read_char(x) || x <= ' ') // read_char will always be true?
	    			break;
	    		s += x;
	    	}
	    	return !s.empty();
	    }

	    template <class T>
	    inline typename std::enable_if<std::is_floating_point<T>::value, bool>::type read_float(T& x) { // No custom implementation -- maybe even slower.
			std::string s;
	        if (!read_string(s)) return false;
	        x = std::stold(s); 
	        return true;
	    }

	    template <class T>
	    inline typename std::enable_if<Internal::is_int<T>::value, bool>::type read_int(T& x) {
	    	using U = typename Internal::internal_get_unsigned<T>::type;

	    	while (true) {
	    		while (input_start_ptr < input_end_ptr && input_buffer[input_start_ptr] < '-') ++input_start_ptr;
	    		if (input_start_ptr < input_end_ptr)
	    			break;
	    		if (!reload())
	    			return false;
	    	}

	    	if (input_start_ptr + INTEGER_WIDTH > input_end_ptr) [[unlikely]]{
	    		reload();
	    	}

	    	if (input_start_ptr == input_end_ptr) [[unlikely]]{
	    		return false;
	    	}
	    	bool minus = false;
	    	if (input_buffer[input_start_ptr] == '-') {
	    		minus = true;
	    		++input_start_ptr;
	    	}

	    	x = 0;
	    	char c;
	    	while (input_start_ptr < input_end_ptr) {
	    		c = input_buffer[input_start_ptr];
	    		if (c < '0' || c > '9') {
	    			break;
	    		}
	    		++input_start_ptr;
	    		x = x * TEN + (c & MASK);
	    	}
	    	if (minus) x = -x;
	    	return true;
	    }
		inline void flush() {
	        fwrite_unlocked(std::begin(output_buffer), sizeof(char), output_end_ptr, write_fptr);
	        output_end_ptr = 0;
	    }

	    template <typename T>
	    IO& operator >> (T& x) {
	        static_assert(Internal::is_custom<T>::value or Internal::is_default<T>::value or
	                      Internal::is_iterable<T>::value or Internal::is_applyable<T>::value or is_floating_point<T>::value);
	        static_assert(!Internal::is_bool<T>::value);
	        bool was_read = false;
	        if constexpr (Internal::is_custom<T>::value) {
	            typename T::internal_value_type y;
	            was_read = read_int(y);
	            x = y;
	        } else if constexpr (Internal::is_default<T>::value) {
	            if constexpr (Internal::is_string<T>::value) {
	                was_read = read_string(x);
	            } else if constexpr (Internal::is_char<T>::value) {
	                was_read =read_char(x);
	            } else if constexpr (Internal::is_int<T>::value) {
	                was_read = read_int(x);
	            }
	        } 
	        else if constexpr (is_floating_point<T>::value) {
            	was_read = read_float(x);
            }
	        else if constexpr (Internal::is_iterable<T>::value) {
	            for (auto& y : x) operator>>(y);
	        } else if constexpr (Internal::is_applyable<T>::value) {
	            std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
	        }

	        if constexpr (SAFETY_CHECKS and (Internal::is_custom<T>::value or Internal::is_default<T>::value or is_floating_point<T>::value)) {
	        	assert (was_read);
	        }
	        return *this;
	    }

	    inline void write_char(char c) {
	        if (output_end_ptr == BUFFER_SIZE) [[unlikely]] flush();
	        output_buffer[output_end_ptr++] = c;
	    }

	    inline void write_bool(bool b) {
	        if (output_end_ptr == BUFFER_SIZE) [[unlikely]] flush();
	        output_buffer[output_end_ptr++] = b ? '1' : '0';
	    }

	    inline void write_string(const std::string& s) {
	        for (const auto& x : s) write_char(x);
	    }

	    inline void write_string(const char* s) {
	        while (*s) write_char(*s++);
	    }

	    inline void write_string(char* s) {
	        while (*s) write_char(*s++);
	    }

	    template <typename T>
	    inline typename std::enable_if<Internal::is_int<T>::value, void>::type write_int(const T& y) {
	    	using U = typename Internal::internal_get_unsigned<T>::type;

	        if (output_end_ptr > BUFFER_SIZE - INTEGER_WIDTH) flush();
	        if (!y) {
	            output_buffer[output_end_ptr++] = '0';
	            return;
	        }
	        U x = y;
	        if (y < 0) output_buffer[output_end_ptr++] = '-', x = -y;
	        int i = TWELVE;
	        static std::array<char, SIXTEEN> buf{};
	        while (x >= TENTHOUSAND) {
	            memcpy(std::begin(buf) + i,
	                   std::begin(io_pre.num) + (x % TENTHOUSAND) * 4, 4);
	            x /= TENTHOUSAND;
	            i -= 4;
	        }
	        if (x < HUNDRED) {
	            if (x < TEN) {
	                output_buffer[output_end_ptr++] = static_cast<char>('0' + x);
	            } else {
	                std::uint32_t q =
	                    (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >>
	                    MAGIC_SHIFT;
	                std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
	                output_buffer[output_end_ptr] = static_cast<char>('0' + q);
	                output_buffer[output_end_ptr + 1] =
	                    static_cast<char>('0' + r);
	                output_end_ptr += 2;
	            }
	        } else {
	            if (x < THOUSAND) {
	                memcpy(std::begin(output_buffer) + output_end_ptr,
	                       std::begin(io_pre.num) + (x << 2) + 1, 3),
	                    output_end_ptr += 3;
	            } else {
	                memcpy(std::begin(output_buffer) + output_end_ptr,
	                       std::begin(io_pre.num) + (x << 2), 4),
	                    output_end_ptr += 4;
	            }
	        }
	        memcpy(std::begin(output_buffer) + output_end_ptr,
	               std::begin(buf) + i + 4, TWELVE - i);
	        output_end_ptr += TWELVE - i;
	    }

	    template <typename T_>
	    IO& operator << (T_&& x) {
	        using T = typename std::remove_cv<
	            typename std::remove_reference<T_>::type>::type;
	        static_assert(Internal::is_custom<T>::value or Internal::is_default<T>::value or
	                      Internal::is_iterable<T>::value or Internal::is_applyable<T>::value);
	        if constexpr (Internal::is_custom<T>::value) {
	            write_int(x.get());
	        } else if constexpr (Internal::is_default<T>::value) {
	            if constexpr (Internal::is_bool<T>::value) {
	                write_bool(x);
	            } else if constexpr (Internal::is_string<T>::value) {
	                write_string(x);
	            } else if constexpr (Internal::is_char<T>::value) {
	                write_char(x);
	            } else if constexpr (Internal::is_int<T>::value) {
	                write_int(x);
	            }
	        } else if constexpr (Internal::is_iterable<T>::value) {
	            // strings are immune
	            using E = decltype(*std::begin(x));
	            constexpr char sep = needs_newline<E> ? '\n' : ' ';
	            int i = 0;
	            for (const auto& y : x) {
	                if (i++) write_char(sep);
	                operator<<(y);
	            }
	        } else if constexpr (Internal::is_applyable<T>::value) {
	            // strings are immune
	            constexpr char sep =
	                (any_needs_newline<
	                    T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
	                    ? '\n'
	                    : ' ';
	            int i = 0;
	            std::apply(
	                [this, &sep, &i](auto const&... y) {
	                    (((i++ ? write_char(sep) : void()), this->operator<<(y)),
	                     ...);
	                },
	                x);
	        }
	        return *this;
	    }
	    IO& operator << (IO<SAFETY_CHECKS>& (*func)(IO<SAFETY_CHECKS>&)) {
	    	return func(*this);
	    }
	    IO* tie(std::nullptr_t) { return this; }
	    inline void sync_with_stdio(bool) {}
	};
	IO<false> Io(stdin, stdout);

	template <const bool SAFETY_CHECKS>
	FastIO::IO<SAFETY_CHECKS>& endl (FastIO::IO<SAFETY_CHECKS>& os){
		os.write_char('\n');
		os.flush();
		return os;
	}

	#define cin FastIO::Io
	#define cout FastIO::Io

};
using FastIO::endl;
/*/-----------------------------Code begins----------------------------------/*/


namespace RMQ {
	template<typename T, class F, const bool indexable, const bool idempotent>
	struct static_rmq{
		static_assert (!indexable && !idempotent);
		vector<T> a;	
		vector<vector<T>> table;
		F op;
		static_rmq(const vector<T>& arr, F _op): op(_op){
			build(arr);
		}
		static_rmq(F _op): op(_op) {}

		inline void clear() {
			a.clear(); 
			table.clear();
		}
		void build(const vector<T>& arr) {
			clear();
			a = arr; 
			int n = 1; while (n < static_cast<int>(arr.size())) n <<= 1;
			a.resize(n);
			int half;
		    for(int h = 0, _range = 2; _range <= n; h++, _range <<= 1) {
		    	table.emplace_back(n);
		        half = _range >> 1;
		        for(int i = half; i < n; i += _range) {
		            table[h][i] = a[i];
		            table[h][i - 1] = a[i - 1];
		            for(int j = i - 2; j >= i - half; j--){
		                table[h][j] = op(table[h][j + 1], a[j]);
		            }

		            for(int j = i + 1; j < i + half; j++){
		                table[h][j] = op(table[h][j - 1], a[j]);
		            }
		        }
		    }
		}

		inline T query(int l, int r) const {
			if (l == r) 
				return a[l];
			int h = 31 ^ __builtin_clz(l ^ r);
			return op(table[h][l], table[h][r]);
		}
	};

	template<typename T, class F, const bool indexable>
	struct static_rmq<T, F, indexable, true>{
		static_assert (!indexable);
		vector<vector<T>> table;
		F op;
		static_rmq(F _op): op(_op) {}	
		static_rmq(const vector<T>& arr, F _op): op(_op) {
			build(arr);
		}

		inline void clear() {
			table.clear();
		}
		void build(const vector<T>& arr) {
			clear();
			int n = static_cast<int>(arr.size());
			table.emplace_back(arr);
			for(int h = 1, range = 2; range <= n; ++h, range <<= 1){
				table.emplace_back(n - range + 1);
				int half = range >> 1;
				for(int i = 0; i + range <= n; ++i){
					table[h][i] = op(table[h - 1][i], table[h - 1][i + half]);
				}
			}
		}

		static inline uint32_t msb_index(uint32_t x){
			return 31 ^ __builtin_clz(x);
		}

		inline T query(int l, int r) const {
			if (l == r)
				return table[0][l];
			int j = msb_index(r - l);
			return op(table[j][l], table[j][r - (1 << j) + 1]);
		}
	};

	template<class F>
	struct static_rmq<uint32_t, F, true, true> {

		static constexpr uint32_t b = 32;
		static constexpr uint32_t shift = 5;
	    static constexpr uint32_t all_mask = -1U;
	    static constexpr uint32_t masks[] = {
	        (1U << 0) - 1,  (1U << 1) - 1,  (1U << 2) - 1, (1U << 3) - 1,  (1U << 4) - 1,  (1U << 5) - 1,
	        (1U << 6) - 1,  (1U << 7) - 1,  (1U << 8) - 1, (1U << 9) - 1,  (1U << 10) - 1, (1U << 11) - 1,
	        (1U << 12) - 1, (1U << 13) - 1, (1U << 14) - 1, (1U << 15) - 1, (1U << 16) - 1, (1U << 17) - 1,
	        (1U << 18) - 1, (1U << 19) - 1, (1U << 20) - 1, (1U << 21) - 1, (1U << 22) - 1, (1U << 23) - 1,
	        (1U << 24) - 1, (1U << 25) - 1, (1U << 26) - 1, (1U << 27) - 1, (1U << 28) - 1, (1U << 29) - 1,
	      	(1U << 30) - 1, (1U << 31) - 1, -1U};

	   	static_assert (all_mask == masks[b] && (1u << shift) == b);
		static inline uint32_t lsb(uint32_t x) {
			return x & -x;
		}
		static inline uint32_t msb_index(uint32_t x){
			return 31 ^ __builtin_clz(x);
		}

		uint32_t n;
		vector<uint32_t> mask;
		vector<vector<int>> table;
		F op;
		inline uint32_t small_query(uint32_t r, uint32_t size = b) const {
			uint32_t dist_from_r = msb_index(mask[r] & masks[size]);
			return r - dist_from_r;
		}

		static_rmq(int _n, F _op): op(_op) { build(_n); }
		static_rmq(F _op): op(_op) {}
		template<typename T>
		static_rmq(const vector<T>& a, F _op): static_rmq(a.size(), _op) {}

		inline void clear(){
			mask.clear();
			table.clear();
		}
			

		void build(int _n) {
			clear();
			n = _n; mask.resize(_n);

			uint32_t curr_mask = 0;
			for (int i = 0; i < static_cast<int>(n); i++) {
				curr_mask = (curr_mask << 1) & all_mask;
				while (curr_mask > 0){
					uint32_t lo = lsb(curr_mask);
					if (static_cast<int>(op(i - msb_index(lo), i)) == i){
						curr_mask ^= lo;
					}
					else
						break;
				}
				curr_mask |= 1;
				mask[i] = curr_mask;
			}
			uint32_t small_n = n / b;
			table.resize(1, vector<int>(small_n));
			for (int i = 0; i < static_cast<int>(small_n); i++) 
				table[0][i] = small_query(b * i + b - 1);

			for (uint32_t j = 1, pow_2 = 2, base_ = 1; pow_2 <= small_n; pow_2 <<= 1, base_ <<= 1, ++j){
				table.emplace_back(small_n - pow_2 + 1);
				for (int i = 0; i + pow_2 <= small_n; i++){
					table[j][i] = op(table[j - 1][i], table[j - 1][i + base_]);
				}
			}
		}
		
		inline uint32_t query(int l, int r) const {
			if (r - l + 1 <= static_cast<int>(b))
				return small_query(r, r - l + 1);
			
			uint32_t ans = small_query(l + b - 1);
			uint32_t r_ans = small_query(r);
			l = (l >> shift) + 1;
			r >>= shift;
	        if (l < r) {
	            int j = msb_index(r - l);
	            ans = op(ans, op(table[j][l], table[j][r - (1 << j)]));
	        }
			return op(ans, r_ans);
		}
	};

	template<class F>
	constexpr uint32_t RMQ::static_rmq<uint32_t, F, true, true>::masks[];

};

template<class F>
using indexed_rmq = RMQ::static_rmq<uint32_t, F, true, true>;

template<typename T, class F>
using idempotent_rmq = RMQ::static_rmq<T, F, false, true>;

template<typename T, class F>
using disjoint_rmq = RMQ::static_rmq<T, F, false, false>;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    cin >> a;

    auto cmp = [&] (const int& i, const int& j) {
    	return a[i] > a[j] ? i : j;
    };

    indexed_rmq<decltype(cmp)> d(m, cmp);
    // SparseTable d(a, cmp);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
    	int xs, ys, xf, yf, k;
    	cin >> xs >> ys >> xf >> yf >> k;
    	--ys; --yf;
    	assert (xs > a[ys] && xf > a[yf]);
    	if (((abs(ys - yf) % k) != 0)) {
    		cout << "NO\n";
    		continue;
    	}

    	xs = xs + ((n - xs) / k) * k;
    	xf = xf + ((n - xf) / k) * k;	

    	if (xs != xf) {
    		cout << "NO\n";
    		continue;
    	}
    	// assert (xf == xs);

    	int idx = d.query(min(ys, yf), max(ys, yf));

    	if (a[idx] >= xs){
    		cout << "NO\n";
    	}
    	else{
    		cout << "YES\n";
    	}
    }

}  

int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
	
    
    std::cerr << std::fixed << std::setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();

    int t = 1;
    // std::cin >> t;

    for(int testcase = 1; testcase <= t; ++testcase) {
        // std::cout << "Case #" << testcase << ": ";
        solve();
    }

    auto stop = std::chrono::high_resolution_clock::now(); 
    long double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    #ifdef __LOCAL_KAL013__
        std::cerr << "Time taken : " << duration / 1e9 << "s" << std::endl;     
    #endif
}